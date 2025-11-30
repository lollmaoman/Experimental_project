
#pragma once


#include"Shader.h"
#include<string>
#include<map>
namespace Resources
{
 

	 
	

	static std::map<std::string, Shader> shaders;

	void addShader(std::string name, const char* vertexShader, const char* fragmentShader);

	Shader getShader(std::string name);
	Shader accessShader(std::string name);




}