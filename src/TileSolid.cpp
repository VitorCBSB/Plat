/*
 * TileSolid.cpp
 *
 *  Created on: 26/12/2013
 *      Author: vitor
 */

#include "TileSolid.h"

TileSolid::TileSolid(Rect hitBox, TileSetPtr tileSet, int tileIndex) :
		Tile(hitBox, tileSet, tileIndex) {

}

TileSolid::~TileSolid() {
}

void TileSolid::onCollision(TestObjPtr player) {
	// TODO: Implementar empurrada
}
