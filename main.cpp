#include<iostream>
#include <glm/glm/glm.hpp>
#include<glm/glm/gtc/matrix_transform.hpp>
#include<glm/glm/gtc/type_ptr.hpp>
#include"triangle.h"
#include"triangleCollision.h"
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"core.h"
#include"Shader.h"
#include"ResourceNamespace.h"
#include"input.h"

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
    Core::setMatrices();
    //Input::window=window;



    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        Core::render();

      

       // processInput(window);
      //  glfwSetKeyCallback(window, keyCallBack);
        input::handleInput(window);
        
        glfwSwapBuffers(window);
        glfwPollEvents();

    }
    

}

/*

First make easy to use ResourceManager 

ResourceManager:

1. for shaders: it takes in fragmentShader.txt,vertexShader.txt and string as the name
2. then stores it in a static map
3. we can access the map using the getter function
4. alos display all shader names 












*/