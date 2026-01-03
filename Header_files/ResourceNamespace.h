
#pragma once


#include"Shader.h"
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<sstream>
#include<fstream>

namespace Resources
{
 

	 
	

	static std::map<std::string, Shader> shaders;
	static std::vector<std::string> shadersList;

	Shader getCompiledShader(const char* vertexShader, const char* fragmentShader);
	void addShader(std::string name, const char* vertexShader, const char* fragmentShader);
	void getShaderList();

	Shader getShader(std::string name);
	Shader accessShader(std::string name);




}