#include<iostream>
#include <glm/glm/glm.hpp>
#include<glm/glm/gtc/matrix_transform.hpp>
#include<glm/glm/gtc/type_ptr.hpp>
#include"triangle.h"
#include"triangleCollision.h"
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"Shader.h"
#include"ResourceNamespace.h"


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

    Triangle triangle(glm::vec2(0.0f, 0.0f), glm::vec2(0.5f, 0.0f), glm::vec2(0.5f, 0.5f));
    Resources::addShader("basic", "triangleShape.vert", "triangleColor.frag");
    Resources::getShaderList();

    Triangle triangle1(glm::vec2(-1.0f, 0.43f), glm::vec2(-0.1f, 0.2f), glm::vec2(-0.1f, -0.4f));

    std::cout << performCollisionCheck(triangle, triangle1);

   // Triangle triangle1(glm::vec2(-5.0f, -5.0f), glm::vec2(-7.0f, -9.0f), glm::vec2(-1.0f, 0.0f));


    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        
        Resources::accessShader("basic").Use();
        glBindVertexArray(triangle.VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(triangle1.VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

       // processInput(window);
      //  glfwSetKeyCallback(window, keyCallBack);
        glfwSwapBuffers(window);
        glfwPollEvents();

    }

	//Triangle triangle(glm::vec2(5.0f, 5.0f), glm::vec2(0.0f, 0.0f), glm::vec2(10.0f, 0.0f));
   // Resources::addShader("basic", "triangleShape.vert", "triangleColor.frag");
   // Resources::getShaderList();

	

	//Triangle triangle1(glm::vec2(-5.0f, -5.0f), glm::vec2(-7.0f, -9.0f), glm::vec2(-1.0f, 0.0f));
	

	

	

	
}

/*

First make easy to use ResourceManager 

ResourceManager:

1. for shaders: it takes in fragmentShader.txt,vertexShader.txt and string as the name
2. then stores it in a static map
3. we can access the map using the getter function
4. alos display all shader names 












*/