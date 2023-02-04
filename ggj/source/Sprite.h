#pragma once
#include "Texture.h"
#include "Maths.h"
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

class GameObject {

public:
	GameObject() : position(0, 0) {}
	vec2 position;
	SDL_Rect renderRect;
};

class Sprite : public GameObject{
public:
	
	Sprite(const char* filename) : texture(filename) { sourceRect = { 0, 0, texture.surface->w, texture.surface->h }; }
	Sprite(const Sprite& sprite) = delete;

	Sprite(Sprite&& other) : texture(std::move(other.texture)), sourceRect(other.sourceRect) { }
	Sprite operator=(Sprite&& other) { Sprite temp(std::move(other)); return temp; }

	void render() { SDL_RenderCopy(Render::renderer, texture.texture, &sourceRect, &(GameObject::renderRect)); }
	SDL_Rect sourceRect;
	Texture texture; 
private:
};

class SpriteSheet : public GameObject {
public:
	SpriteSheet(const std::vector<std::string>& animationSheets);
	~SpriteSheet();
	void update();
	void render();
private:
	float animationSpeed =  0.1;
	float animationTimer = 0;

	unsigned short currentAnimationIndex = 0;
	std::string currentAnimation;
	short unsigned nframes = 11, size = 32;
	std::unordered_map<std::string, Sprite*> animations;
};