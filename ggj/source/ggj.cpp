// SDL2 Hello, World!
// This should display a white screen for 2 seconds
// compile with: clang++ main.cpp -o hello_sdl2 -lSDL2
// run with: ./hello_sdl2


#define SDL_MAIN_HANDLED
#include "Render.h"
#include "GameLoop.h"

SDL_Renderer* Render::renderer = nullptr;
SDL_Window* Render::window = nullptr;
float Render::deltaTime = 0;
uint64_t Render::now = 0;
uint64_t Render::last = 0;


int main(int argc, char* args[]) {
	Render::init(1024, 512);
	GameLoop gameLoop;
	while (gameLoop.keepAlive()) {
		gameLoop.update();
		gameLoop.render();
	}
	Render::quit();
	return 0;
}