#ifndef INPUT_H
#define INPUT_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"viewport.h"
namespace input

{
	
	extern double cursorOriginalX;
	extern double cursorOriginalY;

	extern double cursorX;
	extern double cursorY;

	extern double cursorViewportX;
	extern double cursorViewportY;

	extern double xOffset;
	extern double yOffset;

	extern GLFWwindow* window;
	extern bool keys[1024];

	bool onToggle(int input_key);

	bool onPressed(int input_key);

	bool onLeftClick();

	bool onLeftClickHold();

	bool onRightClick();

	bool onRightClickHold();

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int modifier);

	void mouse_callback(GLFWwindow* window, int button, int action, int mods);
	
//	void updateCursor(viewport &viewport);
	void initWindow(GLFWwindow* window1);
	void setCallbacks();
	void updateCursorPos(viewport &screen);

	void updateOffsets();
	

}









#endif