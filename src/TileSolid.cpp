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
	Vector2 overlap = player->rect.intersection(this->box);

	if (fabs(overlap.y) > fabs(overlap.x)) {
		overlap.y = 0;
		player->velocity.x = 0;
	} else {
		overlap.x = 0;
		player->velocity.y = 0;
	}
	player->rect.position += overlap;
}
