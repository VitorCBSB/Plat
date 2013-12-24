/*
 * TileSet.h
 *
 *  Created on: 24/12/2013
 *      Author: vitor
 */

#ifndef TILESET_H_
#define TILESET_H_

#include "SDLBase.h"
#include <string>

class TileSet {
private:
	SDL_Texture* tiles;
	int tileWidth;
	int tileHeight;

public:
	TileSet(std::string fileName, int tileWidth, int tileHeight);
	virtual ~TileSet();
};

#endif /* TILESET_H_ */
