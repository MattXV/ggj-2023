#pragma once

#include "Texture.h"
#include <array>
#include <vector>
#include "physac.h"

class tile {
public:
	tile(const char* filename, SDL_Rect _renderRect) : texture(filename), renderRect(_renderRect) {}
	SDL_Rect renderRect;
	Texture texture;
	PhysicsBody body;
};

class Cave
{
public:
	Cave() {}

	void generate();
	void render();
	void update();

	~Cave() {}
private:
	const static int map_height = 16;
	const static int map_width = 32;

	const static int source_tile_size = 32;
	const static int render_tile_size = 32;


	std::array<std::array<short, map_width>, map_height> map;
	std::vector<std::vector<tile*>> tiles;


};