#pragma once
#include "Render.h"

class Texture {
public:
	Texture(const Texture& other) = delete;
	Texture(Texture&& other) noexcept {
		texture = other.texture;
		surface = other.surface;
		other.texture = nullptr;
		other.surface = nullptr;
	}
	Texture(const char* filename) {
		surface = IMG_Load(filename);
		if (!surface) {
			__debugbreak();
		}
		texture = SDL_CreateTextureFromSurface(Render::renderer, surface);
	}
	~Texture() {
		SDL_DestroyTexture(texture);
		SDL_FreeSurface(surface);
	}

	SDL_Texture* texture = nullptr;
	SDL_Surface* surface = nullptr;
private:
};