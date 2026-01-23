#include<iostream>
#include <glm/glm/glm.hpp>
#include<glm/glm/gtc/matrix_transform.hpp>
#include<glm/glm/gtc/type_ptr.hpp>
#include"triangle.h"
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"core.h"
#include"Shader.h"
#include"ResourceNamespace.h"
#include"input.h"
#include"Utility.h"

float deltaTime = 0.0f;
float lastFrame = 0.0f;
int main()
{
	
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);

    Core::defineShapes();
    Core::setViewPort(window);
   
    input::initWindow(window);

    Box b1(glm::vec2(3.0f, 1.0f), glm::vec2(6.0f, 1.0f), glm::vec2(6.0f, 0.0f), glm::vec2(3.0f, 0.0f));
    Box b2(glm::vec2(-1.0f, -2.0f), glm::vec2(3.0f, 3.0f), glm::vec2(5.0f, 0.0f), glm::vec2(2.0f, -1.0f));

    Box b3(glm::vec2(0.0f, 0.0f), glm::vec2(3.0f, 3.0f), glm::vec2(5.0f, 0.0f), glm::vec2(2.0f, -1.0f));
 


    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        Core::setMatrices();
       
        float currentFrame = (float)glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

      

        
        Core::update();
        Core::render();
        

        glfwSwapBuffers(window);
        glfwPollEvents();

    }
    

}

