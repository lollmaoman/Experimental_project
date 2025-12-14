#include"input.h"
#include<iostream>

namespace input
{
	bool Released[GLFW_KEY_LAST]{ false };
	bool Pressed[GLFW_KEY_LAST]{ false };
	bool Toggle[GLFW_KEY_LAST]{ false };
	



	bool onToggle(int input_key)
	{
		
		
		if (Toggle[input_key])
		{
			
			Toggle[input_key] = false;
			return true;
		}
		
		return false;

	}

	bool onPressed(int input_key)
	{
		if (Pressed[input_key])

			return true;
		
		return false;
	}
	


	void key_callback(GLFWwindow* window, int key, int scancode, int action, int modifier)
	{
		if (action == GLFW_PRESS)

		{
			Toggle[key] = true;
			Pressed[key] = true;
			
		}
		if (action == GLFW_RELEASE)
		{
			Released[key] = true;
			Pressed[key] = false;
			

		}
		

	}

	void handleInput(GLFWwindow* window)
	{
		glfwSetKeyCallback(window, key_callback);


	}
}



