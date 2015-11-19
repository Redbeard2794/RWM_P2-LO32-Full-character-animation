#include "stdafx.h"
#include "AnimatedObject.h"

//constructor, params: pointer to renderer, number of frames, speed of animation, path to file, x + y positions, width + height and frame width + height
AnimatedObject::AnimatedObject(SDL_Renderer* ren, int numFrames, int speed, std::string path, float x, float y, float w, float h, float frameW, float frameH)
	: numberOfFrames(numFrames), speedOfAnimation(speed), 
	filePath(path)
{
	//load the image onto the surface
	surface = SDL_LoadBMP(filePath.c_str());
	//create the texture from the surface
	texture = SDL_CreateTextureFromSurface(ren,
		surface);

	//set the starting point for the frame on the texture
	srcRect.x = 0;
	srcRect.y = 0;
	//set the width and height of the frame(how much of the sprite sheet do you want to show?)
	srcRect.w = frameW;
	srcRect.h = frameH;

	//set sprites position
	spriteRect.x = x;
	spriteRect.y = y;
	//set the sprites width and height
	spriteRect.w = w;
	spriteRect.h = h;
}

AnimatedObject::~AnimatedObject()
{
	//blank for now
}

void AnimatedObject::Update()
{
	//get the number of ticks since the program started
	int ticks = SDL_GetTicks();

	//divide the number of ticks by the animation speed
	//then get the modulus of this and the number of frames to get a smooth animation
	int s = (ticks / speedOfAnimation) % numberOfFrames;

	//move through the sprite sheet
	srcRect = { s * srcRect.w, 0, srcRect.w, srcRect.h };
}

//get a pointer to the texture
SDL_Texture* AnimatedObject::getTexture()
{
	return texture;
}

//get a pointer to the surface
SDL_Surface* AnimatedObject::getSurface()
{
	return surface;
}

//get the rectangle used to position the sprite
SDL_Rect AnimatedObject::getSpriteRect()
{
	return spriteRect;
}

//get the 'frame' of the spritesheet to display
SDL_Rect AnimatedObject::getSrcRect()
{
	return srcRect;
}

//set the position
void AnimatedObject::setPosition(float x, float y)
{
	spriteRect.x = x;
	spriteRect.y = y;
}

//set the width and height
void AnimatedObject::setSize(float w, float h)
{
	spriteRect.w = w;
	spriteRect.h = h;
}

//set the size(width and height) of the frame to be drawn
void AnimatedObject::setFrameSize(float w, float h)
{
	srcRect.w = w;
	srcRect.h = h;
}

//set the speed of the animation
void AnimatedObject::setAnimationSpeed(int sp)
{
	speedOfAnimation = sp;
}
