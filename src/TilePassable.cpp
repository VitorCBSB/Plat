/*
 * TilePassable.cpp
 *
 *  Created on: 26/12/2013
 *      Author: vitor
 */

#include "TilePassable.h"

TilePassable::TilePassable(Rect hitBox, TileSetPtr tileSet, int tileIndex) :
		Tile(hitBox, tileSet, tileIndex) {

}

TilePassable::~TilePassable() {
}

void TilePassable::onCollision(TestObjPtr player) {
	// Nao faz nada se colidir com o jogador.
	// A ideia dessa classe é produzir tiles
	// que o jogador possa atravessar
}
