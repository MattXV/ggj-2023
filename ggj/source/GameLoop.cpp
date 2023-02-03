#include "GameLoop.h"

GameLoop::GameLoop(int width, int height)
{

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
	}
	m_window = SDL_CreateWindow(
		"hello_sdl2",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		width, height,
		SDL_WINDOW_SHOWN
	);
	if (m_window == NULL) {
		fprintf(stderr, "could not create window: %s\n", SDL_GetError());
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (m_renderer == NULL) {
		fprintf(stderr, "could not create renderer: %s\n", SDL_GetError());
	}
}

GameLoop::~GameLoop()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
}

void GameLoop::render()
{
	SDL_SetRenderDrawColor(m_renderer, 120, 0, 0, 255);
	SDL_RenderClear(m_renderer);
	SDL_RenderPresent(m_renderer);
}

void GameLoop::update()
{
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
