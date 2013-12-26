/*
 * Tile.h
 *
 *  Created on: 26/12/2013
 *      Author: vitor
 */

#ifndef TILE_H_
#define TILE_H_

#include "Sprite.h"
#include "TileSet.h"
#include "TestObj.h"
#include "Rect.h"
#include <tr1/memory>

class Tile {
private:
	Rect hitBox;
	TileSetPtr tileSet;
	int tileIndex;

public:
	Tile(Rect hitBox, TileSetPtr tileSet, int tileIndex);
	virtual ~Tile();

	virtual bool collidesWith(TestObjPtr player);
	virtual void onCollision(TestObjPtr player) = 0;
	void render(float cameraX, float cameraY);
};

typedef std::tr1::shared_ptr<Tile> TilePtr;

#endif /* TILE_H_ */
