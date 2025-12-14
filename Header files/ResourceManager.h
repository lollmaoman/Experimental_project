#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include<map>
#include<string>
#include<sstream>
#include<fstream>
#include"Texture.h"
#include"Shader.h"

class ResourceManager
{
	
	static std::map<std::string, Shader> Shaders;
	static std::map<std::string, Texture> Textures;


	static Texture loadTextureFromFile(const char* path, bool alpha = false, bool invertY = false);
	static Shader loadShaderFromFile(const char* vertexShader, const char* fragmentShader, const char* geometryShader = nullptr);

public:
	static Shader loadShader(const char* vertexShader, const char* fragmentShader,const std::string shaderName, const char* geometryShader = nullptr);
	static Shader& getShader(const std::string shaderName);
	static Texture loadTexture(const char* path,const std::string textureName, bool alpha = false, bool invertY = false);
	static Texture& getTexture(const std::string textureName);


};










#endif