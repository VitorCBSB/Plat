/*
 * TileSolid.h
 *
 *  Created on: 26/12/2013
 *      Author: vitor
 */

#ifndef TILESOLID_H_
#define TILESOLID_H_

#include "Tile.h"
#include "Rect.h"
#include <tr1/memory>
#include <math.h>

class TileSolid: public Tile {
private:
	float xOverlap(TestObjPtr player);
	float yOverlap(TestObjPtr player);

public:
	TileSolid(Rect hitBox, TileSetPtr tileSet, int tileIndex);
	virtual ~TileSolid();

	void onCollision(TestObjPtr player);
};

typedef std::tr1::shared_ptr<TileSolid> TileSolidPtr;

#endif /* TILESOLID_H_ */
