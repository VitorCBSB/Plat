/*
 * TileSet.cpp
 *
 *  Created on: 24/12/2013
 *      Author: vitor
 */

#include "TileSet.h"

TileSet::TileSet(std::string fileName, int tileWidth, int tileHeight) :
		tiles(SpritePtr(new Sprite(fileName))), tileWidth(tileWidth), tileHeight(
				tileHeight) {
	this->lines = tiles->getWidth() / tileWidth;
	this->columns = tiles->getHeight() / tileHeight;
}

TileSet::~TileSet() {
}

void TileSet::render(int index, int posX, int posY) {
	SDL_Rect clip;
	clip.x = (index % columns) * tileWidth;
	clip.y = (index / lines) * tileHeight;
	clip.w = tileWidth;
	clip.h = tileHeight;

	tiles->clipTexture(clip);
	tiles->render(posX, posY, true);
}
