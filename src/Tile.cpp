/*
 * Tile.cpp
 *
 *  Created on: 26/12/2013
 *      Author: vitor
 */

#include "Tile.h"

Tile::Tile(Rect hitBox, TileSetPtr tileSet, int tileIndex) :
		hitBox(hitBox), tileSet(tileSet), tileIndex(tileIndex) {

}

Tile::~Tile() {
}

bool Tile::collidesWith(TestObjPtr player) {
	return hitBox.collidesWith(player->getHitbox());
}

void Tile::render(float cameraX, float cameraY) {
	if (tileIndex != -1) {
		tileSet->render(tileIndex, hitBox.position.x - cameraX,
				hitBox.position.y - cameraY);
	}
}
