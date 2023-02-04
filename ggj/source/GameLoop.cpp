#include "GameLoop.h"



GameLoop::GameLoop()
{
	
}

GameLoop::~GameLoop()
{
	
}

void GameLoop::render()
{
	Render::clear();

	scene.render();

	Render::present();
}

void GameLoop::update()
{
	scene.update();
}

bool GameLoop::keepAlive()
{
	SDL_Event event_;
	while (SDL_PollEvent(&event_)) {
		if (event_.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}
