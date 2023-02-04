#include "Player.h"

Player::Player() :
	spriteSheet({
		"assets/VirtualGuy/DoubleJump.png",
		"assets/VirtualGuy/Fall.png",
		"assets/VirtualGuy/Hit.png",
		"assets/VirtualGuy/Idle.png",
		"assets/VirtualGuy/Jump.png",
		"assets/VirtualGuy/WallJump.png"	
	})
{
	renderRect = {0, 0, 32, 32};
	
	physicsBody = CreatePhysicsBodyRectangle({ 100, 100 }, 32, 32, 1);
	auto [w, h] = Render::getWindowSize();
	//PhysicsBody floor = CreatePhysicsBodyRectangle((Vector2) { screenWidth / 2.0f, (float)screenHeight }, (float)screenWidth, 100, 10);
	physicsBody->position = { 160, 60 };
	physicsBody->velocity = { 0, 0 };
}

void Player::update()
{
	UpdatePhysics();
	spriteSheet.update();

	const Uint8* keys = SDL_GetKeyboardState(0);
	physicsBody->velocity.x = 0;
	if (keys[SDL_SCANCODE_D]) {
		//PhysicsAddForce(physicsBody, { 10, 0 });
		physicsBody->velocity.x = 0.5f;
		currentState = RUNNING;
	} 
	else if (keys[SDL_SCANCODE_A]) {
		physicsBody->velocity.x = -0.5f;
		currentState = RUNNING;

	}

	if (keys[SDL_SCANCODE_SPACE] && currentState != JUMPING) {
		currentState = JUMPING;
		jumpTimer = 0;
	}

	if (currentState == JUMPING) {
		physicsBody->velocity = { 0, -0.1 };
		jumpTimer += Render::deltaTime;
		if (jumpTimer > jumpDuration) {
			currentState = IDLE;
		}
	}

	if (currentState == IDLE || currentState == RUNNING) {
		physicsBody->velocity.y = 0.1;

	}
	//PhysicsBody body = GetPhysicsBody(0);
	//Vector2 vertex = GetPhysicsSh                                   apeVertex(body, 0);

	//renderRect.x = vertex.x;
	//renderRect.y = vertex.y;
	physicsBody->useGravity = true;
	spriteSheet.renderRect.x = physicsBody->position.x - 16;
	spriteSheet.renderRect.y = physicsBody->position.y - 16;
	spriteSheet.renderRect.w = 32;
	spriteSheet.renderRect.h = 32;
}

void Player::render()
{
	spriteSheet.render();
}
