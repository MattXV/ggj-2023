#include "Cave.h"
#include "cellular_automata.h"

void Cave::generate()
{
	int i = 0;
	
	int* map_ = 0;
	generate_map(map_width, map_height, 18, 5, 1, 1, &map_);
	
	//generate_map(map_width, map_height, 0, 5, 1, 1, &map_);
	for (int y = 0; y < map_height; y++) {
		std::vector<tile*> row;
		for (int x = 0; x < map_width; x++) {
			map[y][x] = map_[y * map_width + x];
			
			SDL_Rect r{ x * render_tile_size, y * render_tile_size, render_tile_size, render_tile_size };
			
			tile* newTile = nullptr;
			switch (map[y][x]) {
			case 0:
				newTile = new tile("assets/floor.png", r);
				break;
			case 1:
				newTile = new tile("assets/wall.png", r);
				newTile->body = CreatePhysicsBodyRectangle({ (float)r.x + 16, (float)r.y + 16 }, render_tile_size, render_tile_size, 0);
				newTile->body->isGrounded = true;
				//newTile->body->enabled = false;

				i++;
				break;
			}
			row.push_back(newTile);
		}
		tiles.push_back(std::move(row));
	}
		printf("%d", i);
	free(map_);
}

void Cave::render()
{
	for (int y = 0; y < map_height; y++) {
		for (int x = 0; x < map_width; x++) {

			const tile& tile = *tiles[y][x];

			SDL_RenderCopy(Render::renderer, tile.texture.texture, nullptr, &tile.renderRect);
		}
	}
}

void Cave::update()
{
}
