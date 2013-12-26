/*
 * TileMap.h
 *
 *  Created on: 25/12/2013
 *      Author: vitor
 */

#ifndef TILEMAP_H_
#define TILEMAP_H_

#include "TileSet.h"
#include <string>

class TileMap {
private:
	TileSetPtr tileSet;

public:
	TileMap(std::string fileName, std::string tileSetFileName, int tileWidth,
			int tileHeight);
	virtual ~TileMap();
};

#endif /* TILEMAP_H_ */
