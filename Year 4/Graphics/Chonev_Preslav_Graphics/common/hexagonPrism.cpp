/* hexagon.h
 Example class to create a generic hexagon object
 Iain Martin October 2018
*/

#include "hexagonPrism.h"

using namespace std;
using namespace glm;

/* Define the vertex attributes for vertex positions and normals.
Make these match your application and vertex shader
You might also want to add colours and texture coordinates */
Hexagon::Hexagon()
{
	attribute_v_coord = 0;
	attribute_v_colours = 1;
	attribute_v_normal = 2;
	numvertices = 24;	
}

Hexagon::~Hexagon(){

}

void Hexagon::makeHexagon() {
	// These were collected by a for loop in the main cpp using a for loop and radiants to calculate the points location.
	GLfloat vertexPositions[] = {
		1.f, 0.f, 0.f,
		0.5f, 0.87f, 0.f,
		0.f, 0.f, 0.f,

		0.5f, 0.87f, 0.f,
		-0.5f, 0.87f, 0.f,
		0.f, 0.f, 0.f,

		-0.5f, 0.87f, 0.f,
		-1.f, 0.f, 0.f,
		0.f, 0.f, 0.f,

		-1.f, 0.f, 0.f,
		-0.5f, -0.87f, 0.f,
		0.f, 0.f, 0.f,

		-0.5f, -0.87f, 0.f,
		0.5f, -0.87f, 0.f,
		0.f, 0.f, 0.f,

		0.5f, -0.87f, 0.f,
		1.f, 0.f, 0.f,
		0.f, 0.f, 0.f,

		1.f, 0.f, -1.f,
		0.5f, 0.87f, -1.f,
		0.f, 0.f, -1.f,

		0.5f, 0.87f, -1.f,
		-0.5f, 0.87f, -1.f,
		0.f, 0.f, -1.f,

		-0.5f, 0.87f, -1.f,
		-1.f, 0.f, -1.f,
		0.f, 0.f, -1.f,

		-1.f, 0.f, -1.f,
		-0.5f, -0.87f, -1.f,
		0.f, 0.f, -1.f,

		-0.5f, -0.87f, -1.f,
		0.5f, -0.87f, -1.f,
		0.f, 0.f, -1.f,

		0.5f, -0.87f, -1.f,
		1.f, 0.f, -1.f,
		0.f, 0.f, -1.f,

		1.f,0.f,0.f,
		1.f,0.f,-1.f,
		0.5f, 0.87f, 0.f,

		0.5f, 0.87f, 0.f,
		0.5f, 0.87f, -1.f,
		1.f,0.f,-1.f,

		0.5f, 0.87f, 0.f,
		0.5f, 0.87f, -1.f,
		-0.5f, 0.87f, 0.f,

		-0.5f, 0.87f, 0.f,
		-0.5f, 0.87f, -1.f,
		0.5f, 0.87f, -1.f,

		-0.5f, 0.87f, 0.f,
		-0.5f, 0.87f, -1.f,
		-1.f, 0.f, 0.f,

		-1.f, 0.f, -1.f,
		-0.5f, 0.87f, -1.f,
		-1.f, 0.f, 0.f,

		-1.f, 0.f, 0.f,
		-1.f, 0.f, -1.f,
		-0.5f, -0.87f, 0.f,

		-1.f, 0.f, -1.f,
		-0.5f, -0.87f, -1.f,
		-0.5f, -0.87f, 0.f,

		-0.5f, -0.87f, -1.f,
		-0.5f, -0.87f, 0.f,
		0.5f, -0.87f, 0.f,

		-0.5f, -0.87f, -1.f,
		0.5f, -0.87f, -1.f,
		0.5f, -0.87f, 0.f,

		0.5f, -0.87f, 0.f,
		1.f, 0.f, 0.f,
		0.5f, -0.87f, -1.f,

		0.5f, -0.87f, -1.f,
		1.f, 0.f, -1.f,
		1.f, 0.f, 0.f,
	};

	GLfloat normals[] = {
		0.f,0.f,1.f, 0.f,0.f,1.f, 0.f,0.f,1.f,
		0.f,0.f,1.f, 0.f,0.f,1.f, 0.f,0.f,1.f,
		0.f,0.f,1.f, 0.f,0.f,1.f, 0.f,0.f,1.f,
		0.f,0.f,1.f, 0.f,0.f,1.f, 0.f,0.f,1.f,
		0.f,0.f,1.f, 0.f,0.f,1.f, 0.f,0.f,1.f,
		0.f,0.f,1.f, 0.f,0.f,1.f, 0.f,0.f,1.f,

		0.f,0.f,-1.f, 0.f,0.f,-1.f,	0.f,0.f,-1.f,
		0.f,0.f,-1.f, 0.f,0.f,-1.f,	0.f,0.f,-1.f,
		0.f,0.f,-1.f, 0.f,0.f,-1.f, 0.f,0.f,-1.f,
		0.f,0.f,-1.f, 0.f,0.f,-1.f, 0.f,0.f,-1.f,
		0.f,0.f,-1.f, 0.f,0.f,-1.f, 0.f,0.f,-1.f,
		0.f,0.f,-1.f, 0.f,0.f,-1.f, 0.f,0.f,-1.f,
	};

	/*
	// Traverse Every side of the hexagon from the ring section
	// Find normal of each vertext
	// Store to the hexagon's normal
	// This is my attempt at calculating the normals for the hexagon prism.
	// I tried using the format of using all 3 verticies that make a triangle calculate their normals and store them.
	// This failed as I couldn't store the actual results even after getting good evaluations for normals as c++ arrays with GL additions in the basic way I am trying is not viable.
	// If I were to revisit this issue I would choose to restructure the format of my classes and the way my classes with objects handle their data to make it easier to access as just vector data.

	for (int x = 108; x < sizeof(vertexPositions); x += 9) {
		GLfloat tempx, tempy, tempz;
		vec3 temp_vec_1_side = vec3(vertexPositions[x], vertexPositions[x + 1], vertexPositions[x + 2]);
		vec3 temp_vec_2_side = vec3(vertexPositions[x + 3], vertexPositions[x + 4], vertexPositions[x + 5]);
		vec3 temp_vec_3_side = vec3(vertexPositions[x + 6], vertexPositions[x + 7], vertexPositions[x + 8]);
		vec3 v1 = temp_vec_2_side - temp_vec_1_side;
		vec3 v2 = temp_vec_3_side - temp_vec_1_side;
		vec3 v3 = cross(v1, v2);
		v3 = normalize(v3);
		for (int n = x; n < x + 3; n++) {
			for (int xyz = n; xyz < n + 3; xyz++) {
				normals_stacked[xyz] = v3[(xyz - n)];
			}
		}
	}
	*/

    float vertexColours[] = {
        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
        
        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,

        0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f
	};

    /* Create the vertex buffer for the hexagon */
	glGenBuffers(1, &positionBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenBuffers(1, &colourObject);
	glBindBuffer(GL_ARRAY_BUFFER, colourObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexColours), vertexColours, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    /* Create the normals  buffer for the hexagon */
    //glGenBuffers(1, &normalsBufferObject);
	//glBindBuffer(GL_ARRAY_BUFFER, normalsBufferObject);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(normals_stacked), normals_stacked, GL_STATIC_DRAW);
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
}


void Hexagon::drawHexagon(int drawmode){
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
	glEnableVertexAttribArray(attribute_v_coord);
	glVertexAttribPointer(attribute_v_coord, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, colourObject);
	glEnableVertexAttribArray(attribute_v_colours);
	glVertexAttribPointer(attribute_v_colours, 4, GL_FLOAT, GL_FALSE, 0, 0);

    /* Bind hexagon normals. Note that this is in attribute index attribute_v_normal */
	//glEnableVertexAttribArray(attribute_v_normal);
	//glBindBuffer(GL_ARRAY_BUFFER, normalsBufferObject);
	//glVertexAttribPointer(attribute_v_normal, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glPointSize(3.f);

    if (drawmode == 1)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Draw points
	if (drawmode == 2)
	{
		glDrawArrays(GL_POINTS, 0, numvertices * 3);
	}
	else // Draw the hexagon in triangles
	{
		glDrawArrays(GL_TRIANGLES, 0, numvertices * 3);
	}
}