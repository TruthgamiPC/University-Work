#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <learnopengl/shader.h>
#include <learnopengl/camera.h>
#include <learnopengl/model.h>

#include <iostream>
#include <stack>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void printGuide();

unsigned int loadTexture(const char* path);
unsigned int loadCubemap(vector<std::string> faces);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// camera
Camera camera(glm::vec3(0.f, -0.3f, 4.5f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

float x, y, z;
bool colour_mode = false;

int pick;

glm::vec3 lightPos(1.0f, 0.0f, 1.0f);

double radians(double degree)
{
    double pi = 3.14159265359;
    return (degree * (pi / 180));
}

// A-=--------------------------------------------------------------------------
// Texture loading methods 
unsigned int loadCubemap(vector<std::string> faces)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

    int width, height, nrChannels;
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
        else
        {
            std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
            stbi_image_free(data);
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return textureID;
}

unsigned int loadTexture(char const* path)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}

// A-=--------------------------------------------------------------------------

int main()
{
    x, y, z = 0.0f;
    // glfw: initialize and configure
    // ------------------------------
    printGuide();
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // tell stb_image.h to flip loaded texture's on the y-axis (before loading model).
    stbi_set_flip_vertically_on_load(false);

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    // build and compile shaders
    // -------------------------
    Shader ourShader("Glitter/Shaders/vertext.vert", "Glitter/Shaders/point.frag");
    Shader lightShader("Glitter/Shaders/light.vert", "Glitter/Shaders/light.frag");
    Shader skyboxShader("Glitter/Shaders/skybox.vert", "Glitter/Shaders/skybox.frag");
    Shader seeThrough("Glitter/Shaders/window.vert", "Glitter/Shaders/window.frag");
    Shader UFOTest("Glitter/Shaders/New folder/bphong.vert", "Glitter/Shaders/New folder/bphong.frag");

    // load models
    // -----------
    Model walls_and_floor("Glitter/Sources/Corner/new_corn.obj");
    Model sphereModel("Glitter/Sources/Sphere/Sphere.obj");
    Model UFO("Glitter/Sources/test/Low_poly_UFO.obj");

    float planeVertices[] = {
        // positions          // texture Coords 
         5.0f, -0.5f,  5.0f,  2.0f, 0.0f,
        -5.0f, -0.5f,  5.0f,  0.0f, 0.0f,
        -5.0f, -0.5f, -5.0f,  0.0f, 2.0f,

         5.0f, -0.5f,  5.0f,  2.0f, 0.0f,
        -5.0f, -0.5f, -5.0f,  0.0f, 2.0f,
         5.0f, -0.5f, -5.0f,  2.0f, 2.0f
    };
    float transparentVertices[] = {
        // positions         // texture Coords (swapped y coordinates because texture is flipped upside down)
        0.0f,  0.5f,  0.0f,  0.0f,  0.0f,
        0.0f, -0.5f,  0.0f,  0.0f,  1.0f,
        1.0f, -0.5f,  0.0f,  1.0f,  1.0f,

        0.0f,  0.5f,  0.0f,  0.0f,  0.0f,
        1.0f, -0.5f,  0.0f,  1.0f,  1.0f,
        1.0f,  0.5f,  0.0f,  1.0f,  0.0f
    };
    float skyboxVertices[] = {
        // positions          
        -1.0f,  1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

        -1.0f,  1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f,  1.0f
    };


    // skybox VAO
    unsigned int skyboxVAO, skyboxVBO;
    {
        glGenVertexArrays(1, &skyboxVAO);
        glGenBuffers(1, &skyboxVBO);
        glBindVertexArray(skyboxVAO);
        glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    }

    // Pane + Transparancy VAO
    unsigned int planeVAO, planeVBO;
    {
        glGenVertexArrays(1, &planeVAO);
        glGenBuffers(1, &planeVBO);
        glBindVertexArray(planeVAO);
        glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), &planeVertices, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    }

    // transparent VAO
    unsigned int transparentVAO, transparentVBO;
    {
        glGenVertexArrays(1, &transparentVAO);
        glGenBuffers(1, &transparentVBO);
        glBindVertexArray(transparentVAO);
        glBindBuffer(GL_ARRAY_BUFFER, transparentVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(transparentVertices), transparentVertices, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        glBindVertexArray(0);
    }
    
    vector<glm::vec3> colour_store
    {
        glm::vec3(1.f,1.f,0.f),
        glm::vec3(1.f,0.f,1.f),
        glm::vec3(0.f,1.f,1.f),
        glm::vec3(1.f,0.f,0.f),
        glm::vec3(0.f,1.f,0.f),
        glm::vec3(0.f,0.f,1.f)
    };

   vector<std::string> faces
    {
        "Glitter/Sources/Skybox/2nd/right.jpg",
        "Glitter/Sources/Skybox/2nd/left.jpg",
        "Glitter/Sources/Skybox/2nd/top.jpg",
        "Glitter/Sources/Skybox/2nd/bottom.jpg",
        "Glitter/Sources/Skybox/2nd/front.jpg",
        "Glitter/Sources/Skybox/2nd/back.jpg"
    };

   // Manually loading the textures for the transparent pane and the cubemap textures
    unsigned int transparentTexture = loadTexture("Glitter/Sources/Corner/window.png");
    unsigned int cubemapTexture = loadCubemap(faces);

    // render loop
    // ------------------------------------------------------------------
    // ------------------------------------------------------------------
    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glm::mat3 normalmatrix;

        // input
        // -----
        processInput(window);
        glfwSetKeyCallback(window, key_callback);

        stack<glm::mat4> model;
        model.push(glm::mat4(1.0f));
       
        // render
        // ------
        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();


        lightShader.use();
        unsigned int lightID = glGetUniformLocation(lightShader.ID, "model");

        lightShader.setMat4("projection", projection);
        lightShader.setMat4("view", view);

        //Light Source
        model.push(model.top());
        {
            // also draw the lamp object
            model.top() = glm::translate(model.top(), lightPos);
            model.top() = glm::scale(model.top(), glm::vec3(0.1f)); // a smaller cube

            //lightShader.setMat4("model", model.top());
            glUniformMatrix4fv(lightID, 1, GL_FALSE, glm::value_ptr(model.top()));
            sphereModel.Draw(lightShader);
        }
        model.pop();

        // Scale the size of the screen.
        model.top() = glm::scale(model.top(), glm::vec3(1.f,1.f,1.f));//scale equally in all axis

        model.top() = glm::translate(model.top(), glm::vec3(x, y, z));

        // Building the shader specifics in advance before loading the entire cube
        ourShader.use();
        ourShader.setInt("material.diffuse", 0);
        ourShader.setInt("material.specular", 1);
        unsigned int modelID = glGetUniformLocation(ourShader.ID, "model");
        unsigned int normalmatrixID = glGetUniformLocation(ourShader.ID, "normalmatrix");

        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);
        ourShader.setVec3("light.position", lightPos);

        // CUBE 1997
        //Default settings for all cube parts in terms of lightning
        ourShader.setVec3("light.ambient", 0.2f, 0.2f, 0.2f);
        ourShader.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f);
        ourShader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
        ourShader.setFloat("light.constant", 1.0f);
        ourShader.setFloat("light.linear", 0.09f);
        ourShader.setFloat("light.quadratic", 0.032f);
        ourShader.setFloat("material.shininess", 5.0f);
        ourShader.setBool("parsed", colour_mode);
        if (colour_mode) {
            ourShader.setVec3("light.colour_in", colour_store[pick]);
        }
       

        {
        // Q1
        model.push(model.top());
        {
            model.top() = glm::translate(model.top(), glm::vec3(-2.0f, -2.f, -0.95f));
            model.top() = glm::scale(model.top(), glm::vec3(1.0f, 1.0f, 1.0f));	 
             

            glUniformMatrix4fv(modelID, 1, GL_FALSE, glm::value_ptr(model.top()));
            normalmatrix = glm::transpose(glm::inverse(glm::mat3(view * model.top())));
            glUniformMatrix3fv(normalmatrixID, 1, GL_FALSE, &normalmatrix[0][0]);
            
            walls_and_floor.Draw(ourShader);
        }
        model.pop();

        //Q2
        model.push(model.top());
        {
            model.top() = glm::translate(model.top(), glm::vec3(-1.f, -2.f, -7.85f));
            model.top() = glm::rotate(model.top(), (float)radians(-90), glm::vec3(0.f, 1.f, 0.f)); //rotating in clockwise direction around y-axis

            model.top() = glm::scale(model.top(), glm::vec3(1.0f, 1.0f, 1.0f));	 
             

            glUniformMatrix4fv(modelID, 1, GL_FALSE, glm::value_ptr(model.top()));
            normalmatrix = glm::transpose(glm::inverse(glm::mat3(view * model.top())));
            glUniformMatrix3fv(normalmatrixID, 1, GL_FALSE, &normalmatrix[0][0]);

            walls_and_floor.Draw(ourShader);
        }
        model.pop();
        
        //Q3
        model.push(model.top());
        {
            model.top() = glm::translate(model.top(), glm::vec3(4.9f, -2.f, 0.05f));
            model.top() = glm::rotate(model.top(), (float)radians(90), glm::vec3(0.f, 1.f, 0.f)); //rotating in clockwise direction around y-axis
            model.top() = glm::scale(model.top(), glm::vec3(1.0f, 1.0f, 1.0f));	 
             

            glUniformMatrix4fv(modelID, 1, GL_FALSE, glm::value_ptr(model.top()));
            normalmatrix = glm::transpose(glm::inverse(glm::mat3(view * model.top())));
            glUniformMatrix3fv(normalmatrixID, 1, GL_FALSE, &normalmatrix[0][0]);

            walls_and_floor.Draw(ourShader);
        }
        model.pop();

        //Q4
        model.push(model.top());
        {

            model.top() = glm::translate(model.top(), glm::vec3(5.9f, -2.f, -6.85f));

            model.top() = glm::rotate(model.top(), (float)radians(180), glm::vec3(0.f, 1.f, 0.f)); //rotating in clockwise direction around y-axis
          
            model.top() = glm::scale(model.top(), glm::vec3(1.0f, 1.0f, 1.0f));	 
             

            glUniformMatrix4fv(modelID, 1, GL_FALSE, glm::value_ptr(model.top()));
            normalmatrix = glm::transpose(glm::inverse(glm::mat3(view * model.top())));
            glUniformMatrix3fv(normalmatrixID, 1, GL_FALSE, &normalmatrix[0][0]);

            walls_and_floor.Draw(ourShader);
        }
        model.pop();

        //Q5
        model.push(model.top());
        {
            model.top() = glm::translate(model.top(), glm::vec3(-1.f, -3.9f, 0.05f));
            model.top() = glm::rotate(model.top(), (float)radians(90), glm::vec3(0.f, 1.f, 0.f));
            model.top() = glm::rotate(model.top(), (float)radians(180), glm::vec3(1.f, 0.f, 0.f)); //rotating in clockwise direction around y-axis
           
            model.top() = glm::scale(model.top(), glm::vec3(1.0f, 1.0f, 1.0f));	 
             

            glUniformMatrix4fv(modelID, 1, GL_FALSE, glm::value_ptr(model.top()));
            normalmatrix = glm::transpose(glm::inverse(glm::mat3(view * model.top())));
            glUniformMatrix3fv(normalmatrixID, 1, GL_FALSE, &normalmatrix[0][0]);

            walls_and_floor.Draw(ourShader);
        }
        model.pop();

        //Q6
        model.push(model.top());
        {
            //model.top() = glm::rotate(model.top(), (float)radians(-45), glm::vec3(0.f, 1.f, 0.f)); //rotating in clockwise direction around y-axis
            model.top() = glm::translate(model.top(), glm::vec3(-2.f, -3.9f, -6.85f));
            model.top() = glm::rotate(model.top(), (float)radians(180), glm::vec3(0.f, 1.f, 0.f));

            model.top() = glm::rotate(model.top(), (float)radians(180), glm::vec3(0.f, 0.f, 1.f)); //rotating in clockwise direction around y-axis
            model.top() = glm::scale(model.top(), glm::vec3(1.0f, 1.0f, 1.0f));	 
             

            glUniformMatrix4fv(modelID, 1, GL_FALSE, glm::value_ptr(model.top()));
            normalmatrix = glm::transpose(glm::inverse(glm::mat3(view * model.top())));
            glUniformMatrix3fv(normalmatrixID, 1, GL_FALSE, &normalmatrix[0][0]);

            walls_and_floor.Draw(ourShader);
        }
        model.pop();

        //Q7
        model.push(model.top());
        {
                       
            model.top() = glm::translate(model.top(), glm::vec3(5.9f, -3.9f, -0.95f));
            //model.top() = glm::rotate(model.top(), (float)radians(-45), glm::vec3(0.f, 1.f, 0.f)); //rotating in clockwise direction around y-axis
            model.top() = glm::rotate(model.top(), (float)radians(-180), glm::vec3(0.f, 0.f, 1.f)); //rotating in clockwise direction around y-axis
            model.top() = glm::scale(model.top(), glm::vec3(1.0f, 1.0f, 1.0f));	 
             

            glUniformMatrix4fv(modelID, 1, GL_FALSE, glm::value_ptr(model.top()));
            normalmatrix = glm::transpose(glm::inverse(glm::mat3(view * model.top())));
            glUniformMatrix3fv(normalmatrixID, 1, GL_FALSE, &normalmatrix[0][0]);

            walls_and_floor.Draw(ourShader);
        }
        model.pop();
        
        //Q8
        model.push(model.top());
        {
                       
            model.top() = glm::translate(model.top(), glm::vec3(4.9f, -3.9f, -7.85f));
            model.top() = glm::rotate(model.top(), (float)radians(180), glm::vec3(1.f, 0.f, 1.f)); 
            model.top() = glm::scale(model.top(), glm::vec3(1.0f, 1.0f, 1.0f));	

            glUniformMatrix4fv(modelID, 1, GL_FALSE, glm::value_ptr(model.top()));
            normalmatrix = glm::transpose(glm::inverse(glm::mat3(view * model.top())));
            glUniformMatrix3fv(normalmatrixID, 1, GL_FALSE, &normalmatrix[0][0]);

            walls_and_floor.Draw(ourShader);
        }
        model.pop();
        
        }


        UFOTest.use();
        UFOTest.setInt("texture1", 0);
        UFOTest.setMat4("projection", projection);
        UFOTest.setMat4("view", view);
        UFOTest.setVec3("viewPos", camera.Position);
        UFOTest.setVec3("lightPos", lightPos);
        UFOTest.setInt("blinn", true);
        unsigned int modelID2 = glGetUniformLocation(UFOTest.ID, "model");
        
        //UFO extra
        model.push(model.top());
        {
            model.top() = glm::translate(model.top(), glm::vec3(2.05f, -4.f, -4.f));
            model.top() = glm::rotate(model.top(), (float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f));
            model.top() = glm::scale(model.top(), glm::vec3(0.075f, 0.075f, 0.075f));
            glUniformMatrix4fv(modelID2, 1, GL_FALSE, glm::value_ptr(model.top()));

            UFO.Draw(UFOTest);
        }
        model.pop();

        
        // Blending panels
        seeThrough.use();
        seeThrough.setMat4("projection", projection);
        seeThrough.setMat4("view", view);

        {
        // Panel /Front
        model.push(model.top());
        {
            glBindVertexArray(transparentVAO);
            glBindTexture(GL_TEXTURE_2D, transparentTexture);
            model.top() = glm::translate(model.top(), glm::vec3(0.f, -2.95f, 2.f));
            model.top() = glm::scale(model.top(), glm::vec3(3.9f, 3.9f, 1.f));
            seeThrough.setMat4("model", model.top());
            glDrawArrays(GL_TRIANGLES, 0, 6);

        }
        model.pop();

        // Panel /Back
        model.push(model.top());
        {
            glBindVertexArray(transparentVAO);
            glBindTexture(GL_TEXTURE_2D, transparentTexture);
            model.top() = glm::translate(model.top(), glm::vec3(0.f, -2.95f, -9.9f));
            model.top() = glm::scale(model.top(), glm::vec3(3.9f, 3.9f, 1.f));
            seeThrough.setMat4("model", model.top());
            glDrawArrays(GL_TRIANGLES, 0, 6);

        }
        model.pop();

        // Panel /Right
        model.push(model.top());
        {
            glBindVertexArray(transparentVAO);
            glBindTexture(GL_TEXTURE_2D, transparentTexture);
            
            model.top() = glm::translate(model.top(), glm::vec3(7.85f, -2.95f, -1.95f));
            model.top() = glm::rotate(model.top(), (float)radians(90), glm::vec3(0.f, 1.f, 0.f));
            model.top() = glm::scale(model.top(), glm::vec3(3.9f, 3.9f, 1.f));
            seeThrough.setMat4("model", model.top());
            glDrawArrays(GL_TRIANGLES, 0, 6);

        }
        model.pop();

        // Panel /Left
        model.push(model.top());
        {
            glBindVertexArray(transparentVAO);
            glBindTexture(GL_TEXTURE_2D, transparentTexture);
            model.top() = glm::translate(model.top(), glm::vec3(-4.f, -2.95f, -1.95f));
            model.top() = glm::rotate(model.top(), (float)radians(90), glm::vec3(0.f, 1.f, 0.f));
            model.top() = glm::scale(model.top(), glm::vec3(3.9f, 3.9f, 1.f));
            seeThrough.setMat4("model", model.top());
            glDrawArrays(GL_TRIANGLES, 0, 6);

        }
        model.pop();

        //Panel Bot
        model.push(model.top());
        {
            glBindVertexArray(transparentVAO);
            glBindTexture(GL_TEXTURE_2D, transparentTexture);
            model.top() = glm::translate(model.top(), glm::vec3(0.f, -8.9f, -3.9f));
            model.top() = glm::rotate(model.top(), (float)radians(90), glm::vec3(1.f, 0.f, 0.f));
            model.top() = glm::scale(model.top(), glm::vec3(3.9f, 3.9f, 1.f));
            seeThrough.setMat4("model", model.top());
            glDrawArrays(GL_TRIANGLES, 0, 6);

        }
        model.pop();

        //Panel /Top
        model.push(model.top());
        {
            glBindVertexArray(transparentVAO);
            glBindTexture(GL_TEXTURE_2D, transparentTexture);
            model.top() = glm::translate(model.top(), glm::vec3(0.f, 2.95f, -3.9f));
            model.top() = glm::rotate(model.top(), (float)radians(90), glm::vec3(1.f, 0.f, 0.f));
            model.top() = glm::scale(model.top(), glm::vec3(3.9f, -3.9f, 1.f));
            seeThrough.setMat4("model", model.top());
            glDrawArrays(GL_TRIANGLES, 0, 6);

        }
        model.pop();

        }


        // Skybox implementation
        skyboxShader.use();
        skyboxShader.setInt("skybox", 0);

        // draw skybox as last
        glDepthFunc(GL_LEQUAL);  // change depth function so depth test passes when values are equal to depth buffer's content
        skyboxShader.use();
        view = glm::mat4(glm::mat3(camera.GetViewMatrix())); // remove translation from the view matrix
        skyboxShader.setMat4("view", view);
        skyboxShader.setMat4("projection", projection);
        // skybox cube
        glBindVertexArray(skyboxVAO);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);
        glDepthFunc(GL_LESS); // set depth function back to default

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &skyboxVAO);
    glDeleteVertexArrays(1, &planeVAO);

    glDeleteBuffers(1, &skyboxVBO);
    glDeleteBuffers(1, &planeVBO);


    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

void printGuide() {
    std::cout << "---- Camera Controls ----" << endl;
    std::cout << "1. Camera control using the mouse" << endl;
    std::cout << "2. Navigate the scene using WASD keys, resembling movement fromt first person point of view" << endl;
    std::cout << "3. Zoom in and out using scroll wheel" << endl;
    std::cout << "4. Adjust speed of camera movement using : Z / X\n" << endl;
    std::cout << "---- Scene interaction ----" << endl;
    std::cout << "1. To move the cube across x-axis : J & L" << endl;
    std::cout << "2. To move the cube across y-axis : I & K" << endl;
    std::cout << "3. To move the cube across z-axis : U & O" << endl;
    std::cout << "4. Switch on/off the colour change option : Q" << endl;
    std::cout << "5. Switch the inside colour of the cube to a different one: E\n" << endl;
    std::cout << "---- Control light source ----" << endl;
    std::cout << "1. To move the light source across x-axis : 1 & 2" << endl;
    std::cout << "2. To move the light source across x-axis : 3 & 4" << endl;
    std::cout << "3. To move the light source across x-axis : 5 & 6\n" << endl;
    std::cout << "---- Special keys ----" << endl;
    std::cout << "1. Reset light and cube position to default : R" << endl;
}

// process all inputs based on the frame buffer as that is how "getKey" works
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);

    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
        camera.UpdateSpeed(0.1f);

    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
        camera.UpdateSpeed(-0.1f);

    // Transfomring the entire stack of objects (( MOVING EVERYTHING together))
    if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) x -= 0.05f;
    if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) x += 0.05f;
    if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS) y += 0.05f;
    if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS) y -= 0.05f;
    if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS) z -= 0.05f;
    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS) z += 0.05f;

    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) lightPos.x -= 0.05f;
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) lightPos.x += 0.05f;
    if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) lightPos.y -= 0.05f;
    if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS) lightPos.y += 0.05f;
    if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS) lightPos.z -= 0.05f;
    if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS) lightPos.z += 0.05f;
}

//Processes inputs simply when they are pressed, this doesn't allow for holding the button compared to processInput but its more precise for single presses
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_R && action == GLFW_PRESS) {
        x = 0;
        y = 0;
        z = 0;
        lightPos.x = 1.f;
        lightPos.y = 1.f;
        lightPos.z = 1.f;
    }

    if (key == GLFW_KEY_Q && action == GLFW_PRESS) colour_mode = !colour_mode;
    if (key == GLFW_KEY_E && action == GLFW_PRESS) {
        if ((pick + 1) == 6) {
            pick = 0;
        }
        else {
            pick++;
        }
    }
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
}