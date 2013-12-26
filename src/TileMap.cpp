/*
 * TileMap.cpp
 *
 *  Created on: 25/12/2013
 *      Author: vitor
 */

#include "TileMap.h"

TileMap::TileMap(std::string fileName, std::string tileSetFileName,
		int tileWidth, int tileHeight) :
		tileSet(TileSetPtr(new TileSet(tileSetFileName, tileWidth, tileHeight))) {

}

TileMap::~TileMap() {
	// TODO Auto-generated destructor stub
}

