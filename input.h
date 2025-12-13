#ifndef INPUT_H
#define INPUT_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>

namespace input

{
	

	extern bool keys[1024];

	bool onToggle(int input_key);

	bool onPressed(int input_key);
	
	
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int modifier);
	

	void handleInput(GLFWwindow* window);


}









#endif