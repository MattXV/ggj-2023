// SDL2 Hello, World!
// This should display a white screen for 2 seconds
// compile with: clang++ main.cpp -o hello_sdl2 -lSDL2
// run with: ./hello_sdl2
#define SDL_MAIN_HANDLED
#include "GameLoop.h"

int main(int argc, char* args[]) {
	GameLoop gameLoop(900, 600);
	while (gameLoop.keepAlive())
		gameLoop.render();
	return 0;
}