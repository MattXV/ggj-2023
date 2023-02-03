#pragma once


#include <SDL.h>
#include <iostream>

class GameLoop
{
public:
	GameLoop(int width, int height);
	~GameLoop();

	void render();
	void update();
	bool keepAlive();


private:
	SDL_Renderer* m_renderer = nullptr;
	SDL_Window* m_window = nullptr;
};

