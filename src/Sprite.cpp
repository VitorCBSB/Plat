/*
 * Sprite.cpp
 *
 *  Created on: 21/12/2013
 *      Author: vitor
 */

#include "Sprite.h"

Sprite::Sprite(std::string fileName) {
	this->texture = SDLBase::loadImage(fileName);
	this->clip.x = this->clip.y = 0;
	SDL_QueryTexture(texture, NULL, NULL, &clip.w, &clip.h);
	this->hidden = false;
}

Sprite::Sprite(std::string fileName, bool hidden) {
	this->texture = SDLBase::loadImage(fileName);
	this->clip.x = this->clip.y = 0;
	SDL_QueryTexture(texture, NULL, NULL, &clip.w, &clip.h);
	this->hidden = hidden;
}

Sprite::~Sprite() {
	SDL_DestroyTexture(texture);
}

void Sprite::clipTexture(SDL_Rect newClip) {
	this->clip = newClip;
}

// Essa função tenta evitar o 'stretching'
// Que o SDL_RenderCopy faz. :/
void Sprite::render(int x, int y) {
	SDL_Rect dst;
	int textureW, textureH;

	SDL_QueryTexture(texture, NULL, NULL, &textureW, &textureH);

	dst.x = x;
	dst.y = y;
	dst.w = std::min(clip.w, textureW);
	dst.h = std::min(clip.h, textureH);

	SDLBase::renderTexture(texture, &clip, &dst);
}