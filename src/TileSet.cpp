/*
 * TileSet.cpp
 *
 *  Created on: 24/12/2013
 *      Author: vitor
 */

#include "TileSet.h"

TileSet::TileSet(std::string fileName, int tileWidth, int tileHeight) :
		tileWidth(tileWidth), tileHeight(tileHeight) {
	tiles = SDLBase::loadImage(fileName);
}

TileSet::~TileSet() {
	SDL_DestroyTexture(tiles);
}

