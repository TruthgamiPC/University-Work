/*
 fraglight.cpp
 Extended by Preslav Chonev 
*/

/* Link to static libraries, could define these as linker inputs in the project settings instead
if you prefer */
#ifdef _DEBUG
#pragma comment(lib, "glfw3D.lib")
#pragma comment(lib, "glloadD.lib")
#else
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glload.lib")
#endif
#pragma comment(lib, "opengl32.lib")

/* Include the header to the GLFW wrapper class which
   also includes the OpenGL extension initialisation*/
#include "wrapper_glfw.h"
#include <iostream>
#include <stack>

   /* Include GLM core and matrix extensions*/
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtc/type_ptr.hpp>

// Include headers for our objects
#include "sphere.h"
#include "cube.h"
#include "hexagonPrism.h";

using namespace std;
using namespace glm;

const int NUM_PROGRAMS = 3;

GLuint program[NUM_PROGRAMS];		/* Identifiers for the shader prgorams */
GLuint current_program;
GLuint vao;			/* Vertex array (Containor) object. This is the index of the VAO that will be the container for
					   our buffer objects */

GLuint colourmode;	/* Index of a uniform to switch the colour mode in the vertex shader
					  I've included this to show you how to pass in an unsigned integer into
					  your vertex shader. */
GLuint emitmode;
GLuint attenuationmode;

GLuint screenOn;

/* Position and view globals */
GLfloat laptop_up_pannel, up_pannel_inc, x, model_scale, z, y, vx, vy, vz, pop_out, speed, spin, spin_inc;
GLfloat angle_y, angle_inc_y, angle_z, angle_inc_z;
GLuint drawmode;			// Defines drawing mode of sphere as points, lines or filled polygons
GLuint numlats, numlongs;	//Define the resolution of the sphere object

GLfloat light_x, light_y, light_z;

/* Uniforms*/
GLuint modelID[NUM_PROGRAMS], viewID[NUM_PROGRAMS], projectionID[NUM_PROGRAMS], lightposID[NUM_PROGRAMS], normalmatrixID[NUM_PROGRAMS];
GLuint colourmodeID[NUM_PROGRAMS], emitmodeID[NUM_PROGRAMS], attenuationmodeID[NUM_PROGRAMS];

GLfloat aspect_ratio;		/* Aspect ratio of the window defined in the reshape callback*/
GLuint numspherevertices;

Cube aCube, theTable, screenCube;
Sphere aSphere;
Hexagon aHexagon;

/*
This function is called before entering the main rendering loop.
Use it for all your initialisation stuff
*/
void init(GLWrapper* glw)
{
	/* Set the object transformation controls to their initial values */
	x = 0;
	y = 0;
	z = 0;
	speed = 0.5f;
	pop_out = 0;
	vx = 0; vy = 0; vz = 0;
	light_x = 0; light_y = 0.5f; light_z = 0;
	laptop_up_pannel = spin_inc = spin = 0;
	up_pannel_inc = angle_inc_y = angle_inc_z = 0; const float roughness = 0.8;
	model_scale = 1.f;
	aspect_ratio = 1.3333f;
	screenOn = 0;
	colourmode = 1;
	emitmode = 0;
	attenuationmode = 1; // Attenuation is on by default
	numlats = 20;		// Number of latitudes in our sphere
	numlongs = 20;		// Number of longitudes in our sphere

	// Generate index (name) for one vertex array object
	glGenVertexArrays(1, &vao);

	// Create the vertex array object and make it current
	glBindVertexArray(vao);

	/* Load and build the vertex and fragment shaders */
	try
	{
		program[0] = glw->LoadShader("..\\..\\shaders\\fraglight\\poslight.vert", "..\\..\\shaders\\fraglight\\poslight.frag");
		program[1] = glw->LoadShader("..\\..\\shaders\\fraglight\\fraglight.vert", "..\\..\\shaders\\fraglight\\fraglight.frag");
		program[2] = glw->LoadShader("..\\..\\shaders\\fraglight\\fraglight.vert", "..\\..\\shaders\\fraglight\\fraglight_oren_nayar.frag");
	}
	catch (exception& e)
	{
		cout << "Caught exception: " << e.what() << endl;
		cin.ignore();
		exit(0);
	}

	/* Define the same uniforms to send to both shaders */
	for (int i = 0; i < NUM_PROGRAMS; i++)
	{
		glUseProgram(program[i]);
		modelID[i] = glGetUniformLocation(program[i], "model");
		colourmodeID[i] = glGetUniformLocation(program[i], "colourmode");
		emitmodeID[i] = glGetUniformLocation(program[i], "emitmode");
		attenuationmodeID[i] = glGetUniformLocation(program[i], "attenuationmode");
		viewID[i] = glGetUniformLocation(program[i], "view");
		projectionID[i] = glGetUniformLocation(program[i], "projection");
		lightposID[i] = glGetUniformLocation(program[i], "lightpos");
		normalmatrixID[i] = glGetUniformLocation(program[i], "normalmatrix");
	}
	// Define the index which represents the current shader (i.e. default is gouraud)
	current_program = 1;

	/* create our sphere and cube objects */
	aSphere.makeSphere(numlats, numlongs);
	theTable.makeCube(1);
	aCube.makeCube(2);
	screenCube.makeCube(3);
	aHexagon.makeHexagon();
}

/* Called to update the display. Note that this function is called in the event loop in the wrapper
   class because we registered display as a callback function */
void display()
{
	/* Define the background colour */
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	/* Clear the colour and frame buffers */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* Enable depth test  */
	glEnable(GL_DEPTH_TEST);

	/* Make the compiled shader program current */
	glUseProgram(program[current_program]);


	// Define our model transformation in a stack and 
	// push the identity matrix onto the stack
	stack<mat4> model;
	model.push(mat4(1.0f));

	// Define the normal matrix
	mat3 normalmatrix;

	// Projection matrix : 45� Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	mat4 projection = perspective(radians(30.0f), aspect_ratio, 0.1f, 100.0f);

	// Camera matrix
	mat4 view = lookAt(
		vec3(0, 2, 4), // Camera is at (0,2,4), in World Space
		vec3(0, 0, 0), // and looks at the origin
		vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);

	// Apply rotations to the view position. This wil get applied to the whole scene
	view = rotate(view, -radians(vx), vec3(1, 0, 0)); //rotating in clockwise direction around x-axis
	view = rotate(view, -radians(vy), vec3(0, 1, 0)); //rotating in clockwise direction around y-axis
	view = rotate(view, -radians(vz), vec3(0, 0, 1));

	//view = translate(view, vec3(vx,vy,vz));

	// Define the light position and transform by the view matrix
	vec4 lightpos = view * vec4(light_x, light_y, light_z, 1.0);

	// Send our projection and view uniforms to the currently bound shader
	// I do that here because they are the same for all objects
	glUniform1ui(colourmodeID[current_program], colourmode);
	glUniformMatrix4fv(viewID[current_program], 1, GL_FALSE, &view[0][0]);
	glUniformMatrix4fv(projectionID[current_program], 1, GL_FALSE, &projection[0][0]);
	glUniform4fv(lightposID[current_program], 1, &lightpos[0]);
	glUniform1ui(attenuationmodeID[current_program], attenuationmode);


	// --------------------------------------------------------------------------------------------------------------------
	/* Draw a small sphere in the lightsource position to visually represent the light source */
	// Light doesn't scale
	model.push(model.top());
	{
		model.top() = translate(model.top(), vec3(light_x, light_y, light_z));
		model.top() = scale(model.top(), vec3(0.05f, 0.05f, 0.05f)); // make a small sphere
																	 // Recalculate the normal matrix and send the model and normal matrices to the vertex shader																							// Recalculate the normal matrix and send to the vertex shader																								// Recalculate the normal matrix and send to the vertex shader																								// Recalculate the normal matrix and send to the vertex shader																						// Recalculate the normal matrix and send to the vertex shader
		glUniformMatrix4fv(modelID[current_program], 1, GL_FALSE, &(model.top()[0][0]));
		normalmatrix = transpose(inverse(mat3(view * model.top())));
		glUniformMatrix3fv(normalmatrixID[current_program], 1, GL_FALSE, &normalmatrix[0][0]);

		/* Draw our lightposition sphere  with emit mode on*/
		emitmode = 1;
		glUniform1ui(emitmodeID[current_program], emitmode);
		aSphere.drawSphere(drawmode);
		emitmode = 0;
		glUniform1ui(emitmodeID[current_program], emitmode);
	}
	model.pop();

	// Scale the size of the screen.
	model.top() = scale(model.top(), vec3(model_scale, model_scale, model_scale));//scale equally in all axis

		// --------------------------------------------------------------------------------------------------------------------
	// This block of code draws the table
	model.push(model.top());
	{
		// Define the model transformations for the cube
		model.top() = translate(model.top(), vec3(0, -0.425f, 0));
		model.top() = scale(model.top(), vec3(2.5f, 0.85f, 1.0f));

		// Send the model uniform and normal matrix to the currently bound shader,
		glUniformMatrix4fv(modelID[current_program], 1, GL_FALSE, &(model.top()[0][0]));

		// Recalculate the normal matrix and send to the vertex shader
		normalmatrix = transpose(inverse(mat3(view * model.top())));
		glUniformMatrix3fv(normalmatrixID[current_program], 1, GL_FALSE, &normalmatrix[0][0]);

		/* Draw our cube*/
		theTable.drawCube(drawmode);
	}
	model.pop();


	// --------------------------------------------------------------------------------------------------------------------
	// This block of code draws the laptop
	// Laptop features: 
	// 1. Open up
	// 2. Boot up - animation on screen
	// 3. Move on the surface of the table
	// 4. Play an animation when booted up of a hegagon spinning
	model.push(model.top());
	{
		model.top() = translate(model.top(), vec3(x, y, z));
		// Bottom pannel of the laptop

		model.top() = translate(model.top(), vec3(0, -0.187f, 0));
		model.top() = scale(model.top(), vec3(0.8f, 0.10f, 0.5f));

		// Send the model uniform and normal matrix to the currently bound shader,
		glUniformMatrix4fv(modelID[current_program], 1, GL_FALSE, &(model.top()[0][0]));

		// Recalculate the normal matrix and send to the vertex shader
		normalmatrix = transpose(inverse(mat3(view * model.top())));
		glUniformMatrix3fv(normalmatrixID[current_program], 1, GL_FALSE, &normalmatrix[0][0]);

		aCube.drawCube(drawmode);
	}
	model.pop();

	model.push(model.top());
	{
		// Up pannel of the laptop
		model.top() = translate(model.top(), vec3(x, y, z));

		model.top() = translate(model.top(), vec3(0, -0.137f, 0));
		model.top() = translate(model.top(), vec3(0, -0.025f, -0.125f));				 // How to rotate around a specific position.
		model.top() = rotate(model.top(), -radians(laptop_up_pannel), glm::vec3(1, 0, 0));
		model.top() = translate(model.top(), vec3(0, 0.025f, 0.125f));

		model.top() = scale(model.top(), vec3(0.8f, 0.10f, 0.5f));

		// Send the model uniform and normal matrix to the currently bound shader,
		glUniformMatrix4fv(modelID[current_program], 1, GL_FALSE, &(model.top()[0][0]));

		// Recalculate the normal matrix and send to the vertex shader
		normalmatrix = transpose(inverse(mat3(view * model.top())));
		glUniformMatrix3fv(normalmatrixID[current_program], 1, GL_FALSE, &normalmatrix[0][0]);

		aCube.drawCube(drawmode);
	}
	model.pop();

	model.push(model.top());
	{
		model.top() = translate(model.top(), vec3(x, y, z+0.01));

		// cube to represet the mousepad
		model.top() = translate(model.top(), vec3(0, -0.187f, 0));
		model.top() = scale(model.top(), vec3(0.3f, 0.11f, 0.125f));

		// Send the model uniform and normal matrix to the currently bound shader,
		glUniformMatrix4fv(modelID[current_program], 1, GL_FALSE, &(model.top()[0][0]));

		// Recalculate the normal matrix and send to the vertex shader
		normalmatrix = transpose(inverse(mat3(view * model.top())));
		glUniformMatrix3fv(normalmatrixID[current_program], 1, GL_FALSE, &normalmatrix[0][0]);

		screenCube.drawCube(drawmode);
	}
	model.pop();

	// --------------------------------------------------------------------------------------------------------------------

	// This block of code holds the screen
	// Screen will have the key animation and limited functionality to show skills
	model.push(model.top());
	{
		// Make it pop out when button is pressed
		model.top() = translate(model.top(), vec3(x, y + 0.002, z + pop_out));

		model.top() = translate(model.top(), vec3(0, -0.137f, 0));
		model.top() = translate(model.top(), vec3(0, -0.025f, -0.125f));				 // How to rotate around a specific position.
		model.top() = rotate(model.top(), -radians(laptop_up_pannel), glm::vec3(1, 0, 0));
		model.top() = translate(model.top(), vec3(0, 0.025f, 0.125f));

		model.top() = scale(model.top(), vec3(0.7f, 0.05f, 0.4f));

		// Send the model uniform and normal matrix to the currently bound shader,
		glUniformMatrix4fv(modelID[current_program], 1, GL_FALSE, &(model.top()[0][0]));

		// Recalculate the normal matrix and send to the vertex shader
		normalmatrix = transpose(inverse(mat3(view * model.top())));
		glUniformMatrix3fv(normalmatrixID[current_program], 1, GL_FALSE, &normalmatrix[0][0]);

		/* Draw our cube*/
		screenCube.drawCube(drawmode);
	}
	model.pop();


	model.push(model.top());
	{
		// Make it pop out when button is pressed
		model.top() = translate(model.top(), vec3(x, y + 0.002, z + pop_out));

		model.top() = translate(model.top(), vec3(0, -0.137f, 0));

		model.top() = translate(model.top(), vec3(0, -0.025f, -0.125f));		
		model.top() = rotate(model.top(), -radians(laptop_up_pannel), glm::vec3(1, 0, 0));
		model.top() = translate(model.top(), vec3(0, 0.025f, 0.125f));

		model.top() = rotate(model.top(), -radians(spin), glm::vec3(0, -sin(laptop_up_pannel), 0 ));  // Rotating the hexagon around in circle while keeping up witht he rotation applied by moving the screen up.
		model.top() = rotate(model.top(), -radians(90.f), glm::vec3(1, 0, 0));

		model.top() = scale(model.top(), vec3(0.05f, 0.05f, 0.022f));

		// Send the model uniform and normal matrix to the currently bound shader,
		glUniformMatrix4fv(modelID[current_program], 1, GL_FALSE, &(model.top()[0][0]));

		// Recalculate the normal matrix and send to the vertex shader
		normalmatrix = transpose(inverse(mat3(view * model.top())));
		glUniformMatrix3fv(normalmatrixID[current_program], 1, GL_FALSE, &normalmatrix[0][0]);

		/* Draw our cube*/
		aHexagon.drawHexagon(drawmode);
	}
	model.pop();

	// --------------------------------------------------------------------------------------------------------------------

	model.push(model.top());
	{
		// Hegaon that is left on the scene to show the object's properties
		model.top() = translate(model.top(), vec3(1.f, 1.f, 1.f));
		model.top() = scale(model.top(), vec3(0.3f, 0.3f, 0.3f));
		// Send the model uniform and normal matrix to the currently bound shader,
		glUniformMatrix4fv(modelID[current_program], 1, GL_FALSE, &(model.top()[0][0]));
		// Recalculate the normal matrix and send to the vertex shader
		normalmatrix = transpose(inverse(mat3(view * model.top())));
		glUniformMatrix3fv(normalmatrixID[current_program], 1, GL_FALSE, &normalmatrix[0][0]);
		/* Draw our cube*/
		aHexagon.drawHexagon(drawmode);
	}
	model.pop();

	// --------------------------------------------------------------------------------------------------------------------

	glDisableVertexAttribArray(0);
	glUseProgram(0);
	/* Modify our animation variables */
	if (laptop_up_pannel > 135) {
		if (up_pannel_inc > 0) {
			up_pannel_inc = 0;
		}
	}
	else if (laptop_up_pannel < -0.01) {
		if (up_pannel_inc < 0) {
			up_pannel_inc = 0;
		}
	}
	laptop_up_pannel += up_pannel_inc;
	spin += spin_inc;
}


/* Called whenever the window is resized. The new window size is given, in pixels. */
static void reshape(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	aspect_ratio = ((float)w / 640.f * 4.f) / ((float)h / 480.f * 3.f);
}

/* change view angle, exit upon ESC */
static void keyCallback(GLFWwindow* window, int key, int s, int action, int mods)
{
	/* Enable this call if you want to disable key responses to a held down key*/
//	if (action != GLFW_PRESS) return;

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (key == 'E') {
		if (laptop_up_pannel <= 0) {
			up_pannel_inc = 0;
		}
		else {
			up_pannel_inc -= 0.1f;
		}
	}
	if (key == 'Q') {
		if (laptop_up_pannel >= 135) {
			up_pannel_inc = 0;
		}
		else {
			up_pannel_inc += 0.1f;
		}
	}

	if (key == 'X') model_scale -= 0.02f;
	if (key == 'Z') model_scale += 0.02f;

	// moving the laptop in 4 directions on the desk
	if (key == 'A' && x >= -0.42f) x -= 0.02f;
	if (key == 'D' && x <= 0.42f) x += 0.02f;
	if (key == 'W' && z >= -0.1f) z -= 0.02f;
	if (key == 'S' && z <= 0.1f) z += 0.02f;

	if (key == '1') light_x -= 0.05f;
	if (key == '2') light_x += 0.05f;
	if (key == '3') light_y -= 0.05f;
	if (key == '4') light_y += 0.05f;
	if (key == '5') light_z -= 0.05f;
	if (key == '6') light_z += 0.05f;

	if (key == 'J') vx -= speed;
	if (key == 'L') vx += speed;
	if (key == 'I') vy -= speed;
	if (key == 'K') vy += speed;
	if (key == 'O') vz -= speed;
	if (key == 'P') vz += speed;

	if (key == 'R' && action != GLFW_PRESS) {
		pop_out += 0.02f;
		if (pop_out == 0.04f) {
			pop_out = 0.f;
			spin_inc = 0;
			spin = 0;
		}
	}

	if (key == 'T') {
		spin_inc += 1;
	}

	if (key == GLFW_KEY_LEFT_SHIFT) {
		speed += 0.5f;
	}

	if (key == GLFW_KEY_LEFT_CONTROL) {
		speed = 0.5f;
	}


	if (key == GLFW_KEY_SPACE && action != GLFW_PRESS) {
		vx = 0;
		vy = 0;
		vz = 0;

		light_x = 0;
		light_y = 0.5f;
		light_z = 0;

		speed = 0.5f;
	}

	/* Cycle between drawing vertices, mesh and filled polygons */
	if (key == ',' && action != GLFW_PRESS)
	{
		drawmode++;
		if (drawmode > 2) drawmode = 0;
	}

	/* Switch between the vertex lighting shaders and the fragment shader */
	if (key == '.' && action != GLFW_PRESS)
	{
		current_program++;
		if (current_program == 3) current_program = 0;
	}
}

static void print_commands() {
	cout << "Preslav Chonev - Assignment 1 Graphics\n" << endl;
	cout << "Component Controls:" << endl;
	cout << "Q - Open the laptop" << endl;
	cout << "E - Close the laptop" << endl;

	cout << "W - Move the laptop up the table" << endl;
	cout << "A - Move the laptop to the left of the table"  << endl;
	cout << "S - Move the laptop to the right of the table" << endl;
	cout << "D - Move the laptop down the table" << endl;

	cout << "R - Turn on/off the laptop, makes hegagon appear" << endl;
	cout << "T - Trigger laptop hegagon animation" << endl;

	cout << "Z-X - Increase the scale of the main componenets on the scene\n" << endl;

	cout << "Viewing Controls:" << endl;
	cout << "These behave relative to the scene not the point of view\n" << endl;
	cout << "Space bar - Reset the viewing properties of the scene." << endl;
	cout << "Left Shift - Speeds up the view rotating speed." << endl;
	cout << "Left Ctrl - Resets the speed of view rotating.\n" << endl;

	
	cout << "1,2 - Move the light source up and down respectively" << endl;
	cout << "3,4 - Move the light source left and right respectively" << endl;
	cout << "5,6 - Move the light source away or close to the view respectively" << endl;

	cout << "I-K - Rotate the view accross the X-axis" << endl;
	cout << "J-L - Rotate the view accross the Y-axis" << endl;
	cout << "O-P - Rotate the view accross the Z-axis\n" << endl;


	cout << "developer controls" << endl;
	cout << ", - drawmode" << endl;
	cout << ". - change lighitng method" << endl;
}

/* Entry point of program */
int main(int argc, char* argv[])
{
	GLWrapper* glw = new GLWrapper(1024, 768, "Assigment 1");;

	if (!ogl_LoadFunctions())
	{
		fprintf(stderr, "ogl_LoadFunctions() failed. Exiting\n");
		return 0;
	}

	glw->setRenderer(display);
	glw->setKeyCallback(keyCallback);
	glw->setReshapeCallback(reshape);

	print_commands();

	init(glw);

	glw->eventLoop();

	delete(glw);
	return 0;
}