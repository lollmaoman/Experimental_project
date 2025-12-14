#ifndef SHADER_H
#define SHADER_H

#include<glad/glad.h>
#include<string>
#include <glm/glm/glm.hpp>
#include<glm/glm/gtc/matrix_transform.hpp>
#include<glm/glm/gtc/type_ptr.hpp>

class Shader
{
public:
	unsigned int ID;

public:
	
	
	void compile(const char* VertexShader, const char* FragmentShader, const char* GeometryShader = nullptr);

	Shader& Use();

	void setBool(const char* uniformName, const bool value);

	void setFloat(const char* uniformName, const float value);

	void setInt(const char* uniformName, const int value);
	void setVector2f(const char* uniformName,  const glm::vec2 &vector);
	void setVector2f(const char* uniformName, const float vector_x, const float vector_y);
	void setVector3f(const char* uniformName, const glm::vec3& vector);
	void setVector3f(const char* uniformName, const float vector_x, const float vector_y, const float vector_z);
	void setVector4f(const char* uniformName, const glm::vec4& vector);
	void setVector4f(const char* uniformName, const float vector_x, const float vector_y, const float vector_z, const float vector_a);

	void setMat4(const char* uniformName, const glm::mat4& matrix);


private:
	void checkCompileErrors(unsigned int object, std::string type);

};



#endif
