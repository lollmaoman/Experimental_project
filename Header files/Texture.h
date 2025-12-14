#ifndef TEXTURE_H
#define TEXTURE_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"stb_image.h"

class Texture
{
	//bind
	//unbind 
	// return a texture object taking in texture path 1)by default parameters 2)by setting paramters ourselves

	unsigned int ID;
	int height;
	int width;
	int channels;
	unsigned char* data;
public:
	GLenum paramT = GL_REPEAT;
	GLenum paramS = GL_REPEAT;
	GLenum minFilterType = GL_LINEAR;
	GLenum magFilterType = GL_LINEAR;


	Texture(const char* path, bool alpha = false, bool invertY = false);

	
	unsigned int getTextureID();
	void bindTexture();
	


};


#endif
