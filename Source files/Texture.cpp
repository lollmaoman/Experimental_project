#include<iostream>
#include"glad/glad.h"
#include"Texture.h"



Texture::Texture(const char* path, bool alpha , bool invertY )
{
	glGenTextures(1, &ID);
	bindTexture();

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, paramS);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, paramT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilterType);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilterType);

	bindTexture();
	stbi_set_flip_vertically_on_load(invertY);

	data = stbi_load(path, &width, &height, &channels, 0);
	if (!data)
	{
		std::cout << "FAILED TO LOAD TEXTURE AT PATH " << path << "\n";
	}
	else
	{

		glTexImage2D(GL_TEXTURE_2D, 0, alpha ? GL_RGBA : GL_RGB, width, height, 0, alpha ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	stbi_image_free(data);
}
void Texture::bindTexture()
{
	glBindTexture(GL_TEXTURE_2D, ID);
}

unsigned int Texture::getTextureID()
{
	return ID;
}