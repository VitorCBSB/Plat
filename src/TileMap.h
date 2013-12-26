/*
 * TileMap.h
 *
 *  Created on: 25/12/2013
 *      Author: vitor
 */

#ifndef TILEMAP_H_
#define TILEMAP_H_

#include "TileSet.h"
#include "Vector2.h"
#include <string>
#include <stdio.h>
#include <tr1/memory>

#define LINES 10
#define COLUMNS 10
#define LAYERS 1

class TileMap {
private:
	TileSetPtr tileSet;
	int tileWidth;
	int tileHeight;
	Vector2 position;
	int tileMatrix[LAYERS][LINES][COLUMNS];

	void load(std::string fileName);

public:
	TileMap(std::string fileName, std::string tileSetFileName, int tileWidth,
			int tileHeight);
	virtual ~TileMap();

	void render(float cameraX, float cameraY);
	void setPosition(Vector2 newPosition);
};

typedef std::tr1::shared_ptr<TileMap> TileMapPtr;

#endif /* TILEMAP_H_ */