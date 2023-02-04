#pragma once

#include "Sprite.h"
#include "physac.h"

class Player : GameObject {
public:
	enum State { IDLE, RUNNING, JUMPING };
	Player();
	void update();
	void render();
private:
	State currentState = IDLE;
	float jumpTimer = 0;
	float jumpDuration = 0.3;

	SpriteSheet spriteSheet;
	PhysicsBody physicsBody;
};