#pragma once

#include<glm/glm/glm.hpp>
#include<glm/glm/gtc/matrix_transform.hpp>
#include<glm/glm/gtc/type_ptr.hpp>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
void window_size_callback(GLFWwindow* window, int width, int height);

struct viewport
{
	float width = 0.0f;
	float height = 0.0f;

	float staticSlopeX = 1.0f;

	float slopeX = 1.0f;
	float slopeY = 1.0f;

	float static_l = 0.0f;
	float d = 0.0f;
	float l = static_l;
	bool changeLength = false;
	 GLFWwindow* window = nullptr;


	void initViewport(GLFWwindow *window);
	

	glm::mat4 get2DProjection();
	void setCallback();
	void updateViewport(int width,int height);

	
	

	
	
};