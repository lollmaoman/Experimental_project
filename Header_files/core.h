#ifndef CORE_H
#define CORE_H

#include"triangle.h"
#include"ResourceNamespace.h"
#include"Shader.h"
//#include<glad/glad.h>
#include<GLFW/glfw3.h>

namespace Core

{
	
	void setViewPort(GLFWwindow *window);
	void defineShapes();
	void render();
	void setMatrices();
	//void setCallbacks();
	void update(float deltaTime);
	


}



#endif