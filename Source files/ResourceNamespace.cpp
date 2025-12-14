#include"ResourceNamespace.h"


namespace Resources
{

	Shader getCompiledShader (const char* vertexShader, const char* fragmentShader)
	{
		std::string vertex, fragment, geometry;
		try {

			std::stringstream sVertexShader, sFragmentShader;
			std::ifstream VertexShaderFile(vertexShader), FragmentShaderFile(fragmentShader);
			

			sVertexShader << VertexShaderFile.rdbuf();
			sFragmentShader << FragmentShaderFile.rdbuf();

			VertexShaderFile.close();
			FragmentShaderFile.close();

			vertex = sVertexShader.str();
			fragment = sFragmentShader.str();

		
		}
		catch (std::exception e)
		{
			std::cout << "FAILED TO LOAD SHADER FROM FILE \n";
		}
		const char* vertexShaderCode = vertex.c_str();
		const char* fragmentShaderCode = fragment.c_str();
		


		Shader shader;
		shader.compile(vertexShaderCode, fragmentShaderCode);

		return shader;
	}

	
	void addShader(std::string name, const char* vertexShader, const char* fragmentShader)

	{
		

		Shader shader;
		shader = getCompiledShader(vertexShader, fragmentShader);


		shaders.emplace(name, shader);
		shadersList.emplace_back(name);

		

	}
	void getShaderList()
	{

		for(size_t i=0;i<shadersList.size();i++)
		{
			std::cout << i << " " << shadersList[i] << " \n";

		}
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