//#include <SDL\SDL.h>
//#include <SDL\SDL_image.h>
//#include <GL\glew.h>
//#include <GL\glfw.h>
//
//#include "Background.h"
//
//Background::Background()
//{
//	background   = SDL_LoadBMP("bg.bmp");
//	numberColors = background->format->BytesPerPixel;
//}
//
//Background::~Background()
//{
//	if (background)
//	{
//		SDL_FreeSurface(background);
//	}
//}
//
//void Background::drawBackground()
//{
//	if (numberColors == 4) // contains Alpha channel
//	{
//		if (background->format->Rmask == 0x000000ff)
//		{
//			textureFormat = GL_RGBA;
//		}
//		else
//		{
//			textureFormat = GL_BGRA;
//		}
//	}
//	else if (numberColors == 3)
//	{
//		if (background->format->Rmask == 0x000000ff)
//		{
//			textureFormat = GL_RGB;
//		}
//		else
//		{
//			textureFormat = GL_BGR;
//		}
//	}
//
//	glActiveTexture(GL_TEXTURE0);
//	glBindTexture(GL_TEXTURE_2D, texture);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	glTexImage2D(GL_TEXTURE_2D, 0, numberColors, background->w, background->h, 0,
//				 textureFormat, GL_UNSIGNED_BYTE, background->pixels);
//}