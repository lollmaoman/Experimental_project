#include"Shader.h"
#include<iostream>


void Shader::compile(const char* VertexShader, const char* FragmentShader, const char* GeometryShader )
{
	unsigned int sVertex, sFragment, sGeometry;

	sVertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(sVertex, 1, &VertexShader, NULL);
	glCompileShader(sVertex);
	checkCompileErrors(sVertex, "VERTEX");

	sFragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(sFragment, 1, &FragmentShader, NULL);
	glCompileShader(sFragment);
	checkCompileErrors(sFragment, "FRAGMENT");

	if (GeometryShader != nullptr)
	{
		sGeometry = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(sGeometry, 1, &GeometryShader, NULL);
		glCompileShader(sGeometry);
		checkCompileErrors(sGeometry, "GEOMETRY");

	}

	ID = glCreateProgram();
	glAttachShader(ID, sVertex);
	glAttachShader(ID, sFragment);
	if (GeometryShader != nullptr)
	{
		glAttachShader(ID, sGeometry);
	}
	glLinkProgram(ID);
	checkCompileErrors(ID, "PROGRAM");

	glDeleteShader(sVertex);
	glDeleteShader(sFragment);

	if (GeometryShader != nullptr)
	{
		glDeleteShader(sGeometry);
	}


}
Shader& Shader::Use()
{
	glUseProgram(this->ID);
	return *this;
}

void Shader::setInt(const char* uniformName, const int value)
{
	glUniform1i(glGetUniformLocation(ID, uniformName), value);
}
void Shader :: setBool(const char* uniformName, const bool value)
{
	glUniform1i(glGetUniformLocation(ID, uniformName), value);
}

void Shader::setFloat(const char* uniformName, const float value)
{
	glUniform1f(glGetUniformLocation(ID, uniformName), value);
}

void Shader::setVector2f(const char* uniformName,  const glm::vec2 &vector)
{

	glUniform2fv(glGetUniformLocation(ID, uniformName), 1, glm::value_ptr(vector));
}

void Shader::setVector2f(const char* uniformName, const float vector_x, const float vector_y)
{
	glUniform2f(glGetUniformLocation(ID, uniformName), vector_x, vector_y);

}

void Shader::setVector3f(const char* uniformName, const glm::vec3& vector)
{
	glUniform3fv(glGetUniformLocation(ID, uniformName), 1, glm::value_ptr(vector));
}

void Shader::setVector3f(const char* uniformName, const float vector_x, const float vector_y, const float vector_z)
{
	glUniform3f(glGetUniformLocation(ID, uniformName), vector_x, vector_y, vector_z);

}

void Shader::setVector4f(const char* uniformName, const glm::vec4& vector)
{
	glUniform4fv(glGetUniformLocation(ID, uniformName), 1, glm::value_ptr(vector));
}

void Shader::setVector4f(const char* uniformName, const float vector_x, const float vector_y, const float vector_z, const float vector_a)
{
	glUniform4f(glGetUniformLocation(ID, uniformName), vector_x, vector_y, vector_z, vector_a);
}

void Shader::setMat4(const char* uniformName, const glm::mat4& matrix)
{
	glUniformMatrix4fv(glGetUniformLocation(ID, uniformName), 1,GL_FALSE,glm::value_ptr(matrix));
}

void Shader::checkCompileErrors(unsigned int object, std::string type)
{
	int success;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(object, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(object, 1024, NULL, infoLog);
			std::cout << "| ERROR::SHADER: Compile-time error: Type: " << type << "\n"
				<< infoLog << "\n -- --------------------------------------------------- -- "
				<< std::endl;
		}
	}
	else
	{
		glGetProgramiv(object, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(object, 1024, NULL, infoLog);
			std::cout << "| ERROR::Shader: Link-time error: Type: " << type << "\n"
				<< infoLog << "\n -- --------------------------------------------------- -- "
				<< std::endl;
			
		}
		
	}
}