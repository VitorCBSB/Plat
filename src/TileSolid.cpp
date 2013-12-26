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

float TileSolid::xOverlap(TestObjPtr player) {
	if (player->getHitbox().position.x < this->hitBox.position.x) {
		return this->hitBox.position.x - (this->hitBox.w / 2)
				- (player->getHitbox().position.x + (player->getHitbox().w / 2));
	}
	return this->hitBox.position.x + (this->hitBox.w / 2)
			- (player->getHitbox().position.x - (player->getHitbox().w / 2));
}

float TileSolid::yOverlap(TestObjPtr player) {
	if (player->getHitbox().position.y < this->hitBox.position.y) {
		return this->hitBox.position.y - (this->hitBox.h / 2)
				- (player->getHitbox().position.y + (player->getHitbox().h / 2));
	}
	return this->hitBox.position.y + (this->hitBox.h / 2)
			- (player->getHitbox().position.y - (player->getHitbox().h / 2));

}

void TileSolid::onCollision(TestObjPtr player) {
	Vector2 overlap(xOverlap(player), yOverlap(player));

	fabs(overlap.y) > fabs(overlap.x) ? overlap.y = 0 : overlap.x = 0;
	player->setPosition(player->getPosition() + overlap);
}
