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
	} else {
		overlap.x = 0;
		if (player->rect.position.y < this->box.position.y) {
			player->setOnGround(true);
		}
	}
	player->rect.position += overlap;
}
