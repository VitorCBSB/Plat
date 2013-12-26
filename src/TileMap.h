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

#define LINES 20
#define COLUMNS 100
#define LAYERS 3

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

#endif /* TILEMAP_H_ */
