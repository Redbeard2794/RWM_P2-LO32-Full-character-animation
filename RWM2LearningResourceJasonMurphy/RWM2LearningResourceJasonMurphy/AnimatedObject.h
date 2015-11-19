#ifndef ANIMATEDOBJECT_H
#define ANIMATEDOBJECT_H

class AnimatedObject
{
public:
	//constructor, params: pointer to renderer, number of frames, speed of animation, path to file, x + y positions, width + height and frame width + height
	AnimatedObject(SDL_Renderer* ren, int numFrames, int speed, std::string path, float x, float y, float w, float h, float frameW, float frameH);

	//destructor
	~AnimatedObject();

	//update
	void Update();

	//get a pointer to the texture
	SDL_Texture* getTexture();

	//get a pointer to the surface
	SDL_Surface* getSurface();

	//get the rectangle used to position the sprite
	SDL_Rect getSpriteRect();

	//get the 'frame' of the spritesheet to display
	SDL_Rect getSrcRect();

	//set the position
	void setPosition(float x, float y);

	//set the width and height
	void setSize(float w, float h);

	//set the size(width and height) of the frame to be drawn
	void setFrameSize(float w, float h);

	//set the speed of the animation
	void setAnimationSpeed(int sp);
private:
	//the texture
	SDL_Texture* texture;

	//the surface to draw it to
	SDL_Surface* surface;

	//the rectangle used to position the sprite
	SDL_Rect spriteRect;

	//the 'frame' of the spritesheet to display
	SDL_Rect srcRect;

	//the number of frames in the spritesheet
	int numberOfFrames;

	//the speed you want to play the animation at
	int speedOfAnimation;

	//the path to the spritesheet you want to load
	std::string filePath;
};

#endif
