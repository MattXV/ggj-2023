#include "Sprite.h"
#pragma once

SpriteSheet::SpriteSheet(const std::vector<std::string>& animationSheets)
{
	for (const auto& s : animationSheets) {
		std::string key = s.substr(0, s.size() - 4);

		std::string path = std::string(key);
		std::string delimiter = "/";

		size_t pos = 0;
		std::string token;
		while ((pos = path.find(delimiter)) != std::string::npos) {
			token = path.substr(0, pos);
			path.erase(0, pos + delimiter.length());
		}
		//std::cout << s << std::endl;
		animations.insert({ path, new Sprite(s.c_str()) });
	}

	currentAnimation = "Idle";
}

SpriteSheet::~SpriteSheet()
{
	for (auto& it : animations) {
		delete it.second;
	}
}

void SpriteSheet::update()
{
	animationTimer += Render::deltaTime;
	if (animationTimer > animationSpeed) {
		animationTimer = 0;
		currentAnimationIndex = ++currentAnimationIndex % nframes;
	}
}

void SpriteSheet::render()
{
	Sprite& sprite = *animations[currentAnimation];
	sprite.sourceRect.y = 0;
	sprite.sourceRect.w = size;
	sprite.sourceRect.h = size;
	sprite.sourceRect.x = size * currentAnimationIndex;
	SDL_RenderCopy(Render::renderer, sprite.texture.texture, &sprite.sourceRect, &(GameObject::renderRect));
}
