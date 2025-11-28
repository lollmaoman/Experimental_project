#include"ResourceManager.h"
#include<iostream>
#include"stb_image.h"
std::map<std::string, Shader> ResourceManager::Shaders;
std::map<std::string, Texture> ResourceManager::Textures;


Texture ResourceManager::loadTextureFromFile(const char* path, bool alpha , bool invertY )
{
	Texture texture{ path,alpha,invertY};
	return texture;
}

Shader ResourceManager::loadShaderFromFile(const char* vertexShader, const char* fragmentShader, const char* geometryShader )
{
	std::string vertex, fragment, geometry;
	try {

		std::stringstream sVertexShader, sFragmentShader, sGeometryShader;
		std::ifstream VertexShaderFile(vertexShader), FragmentShaderFile(fragmentShader);
		std::ifstream GeometryShaderFile;

		sVertexShader << VertexShaderFile.rdbuf();
		sFragmentShader << FragmentShaderFile.rdbuf();

		VertexShaderFile.close();
		FragmentShaderFile.close();

		vertex = sVertexShader.str();
		fragment = sFragmentShader.str();

		if (geometryShader)
		{
			GeometryShaderFile.open(geometryShader);
			sGeometryShader << GeometryShaderFile.rdbuf();
			GeometryShaderFile.close();
			geometry = sGeometryShader.str();
		}
	}
	catch (std::exception e)
	{
		std::cout << "FAILED TO LOAD SHADER FROM FILE \n";
	}
	const char* vertexShaderCode = vertex.c_str();
	const char* fragmentShaderCode = fragment.c_str();
	const char* geometryShaderCode = (geometryShader ? geometry.c_str() : nullptr);

	
	Shader shader;
	shader.compile(vertexShaderCode, fragmentShaderCode, geometryShaderCode);
	return shader;
}

Shader ResourceManager::loadShader(const char* vertexShader, const char* fragmentShader,const std::string shaderName, const char* geometryShader )
{
	
	if (Shaders.find(shaderName) == Shaders.end())
	{
		Shaders.emplace(shaderName, loadShaderFromFile(vertexShader, fragmentShader, geometryShader));

	}

		return Shaders.at(shaderName);
}

Shader& ResourceManager::getShader(const std::string shaderName)
{
	return Shaders.at(shaderName);
}
Texture ResourceManager::loadTexture(const char* path,const std::string textureName, bool alpha , bool invertY)
{
	if (Textures.find(textureName) == Textures.end())
	{
		Textures.emplace(textureName, loadTextureFromFile(path, alpha, invertY));

	}
	
		return Textures.at(textureName);
}

Texture& ResourceManager::getTexture(const std::string textureName)
{
	return Textures.at(textureName);
}