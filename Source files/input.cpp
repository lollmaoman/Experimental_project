#include"input.h"
#include<iostream>

namespace input
{
	bool Released[GLFW_KEY_LAST]{ false };
	bool Pressed[GLFW_KEY_LAST]{ false };
	bool Toggle[GLFW_KEY_LAST]{ false };
	
	bool leftClick = false;
	bool rightClick = false;

	bool leftClickHold = false;
	bool rightClickHold = false;

	double cursorX = 0;
	double cursorY = 0;

	double cursorOriginalX = 0;
	double cursorOriginalY = 0;

	double xOffset = 0;
	double yOffset = 0;
	
	double firstX = 0;
	double firstY = 0;

	bool first = true;

	GLFWwindow* window = nullptr;

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
	
	bool onLeftClick()
	{
		if (leftClick)
		{
			leftClick = false;
			return true;
		}

		return false;
	}

	bool onLeftClickHold()
	{
		if (leftClickHold)
			return true;

		return false;
	}


	bool onRightClick()
	{
		if (rightClick)
		{
			rightClick = false;
			return true;
		 }

		return false;
	}

	bool onRightClickHold()
	{
		if (rightClickHold)

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

	
	void mouse_callback(GLFWwindow* window, int button, int action, int mods)
	{

		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
		{
			leftClick = true;
			leftClickHold = true;
			

		}
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
		{
			leftClick = false;
			leftClickHold = false;
		}
		if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
		{
			rightClick = true;
			rightClickHold = true;
		}

		if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
		{
			rightClick = false;
			rightClickHold = false;
		}

	
		
	}

	void initWindow(GLFWwindow* window1)
	{
		window = window1;
	}

	
	void setCallbacks()
	{
		glfwSetKeyCallback(window, key_callback);
		glfwSetMouseButtonCallback(window, mouse_callback);
		updateOffsets();
		
	}
	void updateCursorPos(viewport &screen)
	{
		glfwGetCursorPos(window, &cursorOriginalX, &cursorOriginalY);

		if (cursorOriginalX > screen.width)
			cursorOriginalX = screen.width;

		if (cursorOriginalX < 0)
			cursorOriginalX = 0;

		if (cursorOriginalY > screen.height)
			cursorOriginalY = screen.height;

		if (cursorOriginalY < 0)
			cursorOriginalY = 0;

		cursorX = -screen.l + cursorOriginalX * screen.slopeX;
		cursorY = screen.d +  cursorOriginalY * screen.slopeY;


	}
	void updateOffsets()
	{
		
		if (first)
		{
			
			firstX = cursorX;
			firstY = cursorY;
			

			first = false;
		}

		xOffset = cursorX - firstX;
		yOffset = cursorY - firstY;
		
		firstX = cursorX;
		firstY = cursorY;

		
	}
}



