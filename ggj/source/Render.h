#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <utility>

class Render {
public:
	static void init(int width, int height) {
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
		}
		if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) < 0) {
			fprintf(stderr, "could not initialize sdl2_image: %s\n", IMG_GetError());
		}
		window = SDL_CreateWindow(
			"hello_sdl2",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			width, height,
			SDL_WINDOW_SHOWN
		);
		if (window == NULL) {
			fprintf(stderr, "could not create window: %s\n", SDL_GetError());
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == NULL) {
			fprintf(stderr, "could not create renderer: %s\n", SDL_GetError());
		}
	}

	static void quit() {
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		IMG_Quit();
		SDL_Quit();
	}

	static void clear() {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		last = now;
		now = SDL_GetPerformanceCounter();
		deltaTime = (float)(now - last) / (float)SDL_GetPerformanceFrequency();
	}
	static void present() {
		SDL_RenderPresent(renderer);
	}

	static inline std::pair<int, int> getWindowSize() { int w, h; SDL_GetRendererOutputSize(renderer, &w, &h); return std::pair<int, int>(w, h); }


	static SDL_Renderer* renderer;
	static SDL_Window* window;

	static float deltaTime;
private:
	static uint64_t now, last;
};

