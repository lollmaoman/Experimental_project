#include"viewport.h"


void viewport::initViewport(GLFWwindow*window)
{
	this->window = window;


}

glm::mat4 viewport::get2DProjection()
{
	glm::mat4 projection = glm::ortho(-l, l, -d, d, -1.0f, 1.0f);
	return projection;
}

void window_size_callback(GLFWwindow* window, int width, int height)
{
	viewport* vp = static_cast<viewport*>(glfwGetWindowUserPointer(window));

	vp->updateViewport(width, height);
}



void viewport::updateViewport(int width, int height)
{

	glViewport(0, 0, width, height);
	this->width = (float)width;
	this->height = (float)height;

	l = static_l * float(width) / float(height);
	

	slopeX = 2 * l / this->width;
	slopeY = -2 * d / this->height;
}

void viewport::setCallback()
{
	glfwSetWindowUserPointer(window, this);
	glfwSetFramebufferSizeCallback(window, window_size_callback);
}