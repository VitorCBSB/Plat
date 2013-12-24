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
}

TileSet::~TileSet() {
}

