#include"ResourceNamespace.h"


namespace Resources
{
	//std::map<std::string, Shader> shaders;

	void addShader(std::string name, const char* vertexShader, const char* fragmentShader)

	{
		
		Shader shader;
		shader.compile(vertexShader, fragmentShader);

		shaders.emplace(name, shader);

		

	}

	Shader getShader(std::string name)
	{
		return shaders.at(name);


	}

	Shader accessShader(std::string name)
	{
		return shaders.at(name);


	}
}