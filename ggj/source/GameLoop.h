#pragma once


#include "Render.h"
#include <iostream>

#include "Scene.h"

class GameLoop
{
public:
	GameLoop();
	~GameLoop();

	void render();
	void update();
	bool keepAlive();


private:
	Scene scene;
};

