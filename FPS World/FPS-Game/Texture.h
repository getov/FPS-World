#pragma once

class Texture
{
	private:
		GLuint textureID;

	public:
		Texture();
		~Texture();

		bool loadTexture(const char* filename);
		
		GLenum getTexType() const { return GL_TEXTURE_2D; }

		GLuint getTexID() const { return textureID; }
};