/*
 * TileSet.h
 *
 *  Created on: 24/12/2013
 *      Author: vitor
 */

#ifndef TILESET_H_
#define TILESET_H_

#include "Sprite.h"
#include <tr1/memory>
#include <string>

class TileSet {
private:
	SpritePtr tiles;
	int tileWidth;
	int tileHeight;
	int lines;
	int columns;

public:
	TileSet(std::string fileName, int tileWidth, int tileHeight);
	virtual ~TileSet();

	void render(int index, int posX, int posY);
	int getTileWidth() {
		return tileWidth;
	}
	int getTileHeight() {
		return tileHeight;
	}
};

typedef std::tr1::shared_ptr<TileSet> TileSetPtr;

#endif /* TILESET_H_ */
