// RWM2LearningResourceJasonMurphy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main(int argc, char *argv[])
{

	SDL_Event e;
	bool quit = false;

	Renderer renderer;

	AnimatedObject* object1 = new AnimatedObject(renderer.GetRenderer(), 2, 200, "Assets/images/spritesRight.bmp", 50, 50, 50, 64, 32, 32);

	AnimatedObject* object2 = new AnimatedObject(renderer.GetRenderer(), 2, 200, "Assets/images/spritesLeft.bmp", 50, 200, 50, 64, 32, 32);
	object2->setPosition(200, 50);

	AnimatedObject* object3 = new AnimatedObject(renderer.GetRenderer(), 4, 100, "Assets/images/bananaDance.bmp", 50, 200, 64, 64, 32, 35);
	object3->setAnimationSpeed(125);

	while (!quit)
	{
		// Update loop

		renderer.ClearScreen();

		object1->Update();
		renderer.DrawSprite(object1->getTexture(), object1->getSrcRect(), object1->getSpriteRect());

		object2->Update();
		renderer.DrawSprite(object2->getTexture(), object2->getSrcRect(), object2->getSpriteRect());
		
		object3->Update();
		renderer.DrawSprite(object3->getTexture(), object3->getSrcRect(), object3->getSpriteRect());

		//update the screen with rendering operations
		renderer.renderPresent();

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{

			//User requests quit
			if (e.type == SDL_QUIT) //user presses close button on window
			{
				quit = true;
			}

			//User presses a key
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					quit = true;
					break;
				default:
					break;
				}


			}
		}//End Poll Events

	}//End Game loop
	SDL_Quit();
	return 0;
} //End Main

