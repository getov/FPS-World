#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
#include <GL\glew.h>
#include <GL\glfw.h>

#include "Texture.h"

Texture::Texture()
{
	glGenTextures(1, &textureID);
}

Texture::~Texture()
{
	glDeleteTextures(1, &textureID);
}

bool Texture::loadTexture(const char* filename)
{
	SDL_Surface* image = IMG_Load(filename);

	if (!image)
	{
		const char* error = IMG_GetError();
		return false;
	}

	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	float maxAniso;
	glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAniso);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxAniso);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, image->w, image->h, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_SRGB_ALPHA, image->w, image->h, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	
	SDL_FreeSurface(image);	

	return true;
}