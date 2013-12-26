/*
 * TilePassable.h
 *
 *  Created on: 26/12/2013
 *      Author: vitor
 */

#ifndef TILEPASSABLE_H_
#define TILEPASSABLE_H_

#include "Tile.h"
#include "TestObj.h"

class TilePassable: public Tile {
public:
	TilePassable(Rect hitBox, TileSetPtr tileSet, int tileIndex);
	virtual ~TilePassable();

	void onCollision(TestObjPtr player);
};

#endif /* TILEPASSABLE_H_ */
