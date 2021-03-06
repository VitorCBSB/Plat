/*
 * TileMap.cpp
 *
 *  Created on: 25/12/2013
 *      Author: vitor
 */

#include "TileMap.h"

TileMap::TileMap(std::string fileName, std::string tileSetFileName,
		int tileWidth, int tileHeight) :
		tileSet(
				TileSetPtr(
						new TileSet(tileSetFileName, tileWidth, tileHeight))), layers(
				0), lines(0), columns(0), tileWidth(tileWidth), tileHeight(
				tileHeight), position(Vector2(0, 0)) {
	load(fileName);
}

TileMap::~TileMap() {
}

void TileMap::load(std::string fileName) {
	FILE* fp;
	int tileIndex;

	if ((fp = fopen(fileName.c_str(), "r")) == NULL) {
		fprintf(stderr, "TileMap: arquivo %s nao pode ser aberto.",
				fileName.c_str());
		exit(1);
	}

	fscanf(fp, "%d %d %d", &layers, &lines, &columns);

	for (int k = 0; k < layers; k++) {
		for (int i = 0; i < lines; i++) {
			for (int j = 0; j < columns; j++) {
				fscanf(fp, "%d", &tileIndex);
				// Se for a camada mais proxima da tela, entao cria tiles solidos
				if (tileIndex != -1 && k == layers - 1) {
					tileMatrix[k][i][j] = TilePtr(
							new TileSolid(
									Rect(Vector2(j * tileWidth, i * tileHeight),
											tileWidth, tileHeight), tileSet,
									tileIndex));
				} else { // Senao, o tile deve ser atravessavel
					tileMatrix[k][i][j] = TilePtr(
							new TilePassable(
									Rect(Vector2(j * tileWidth, i * tileHeight),
											tileWidth, tileHeight), tileSet,
									tileIndex));
				}
			}
		}
	}

	fclose(fp);
}

void TileMap::render(float cameraX, float cameraY) {
	for (int k = 0; k < layers; k++) {
		for (int i = 0; i < lines; i++) {
			for (int j = 0; j < columns; j++) {
				tileMatrix[k][i][j]->render(cameraX, cameraY);
			}
		}
	}
}

void TileMap::checkCollision(TestObjPtr player) {
	collidingTile collidingTiles[30];
	int n = 0;
	int line, column;

	player->setOnGround(false);

	positionToIndex(player->rect.position, &line, &column);

	for (int i = std::max(0, line - 1); i <= std::min(lines - 1, line + 1); i++) {
		for (int j = std::max(0, column - 1); j <= std::min(columns - 1, column + 1); j++) {
			if (tileMatrix[layers - 1][i][j]->collidesWith(player)) {
				collidingTile temp;
				temp.distanceToPlayer = player->rect.position.distance(
						tileMatrix[layers - 1][i][j]->getBox().position);
				temp.tile = tileMatrix[layers - 1][i][j];

				collidingTiles[n] = temp;
				n++;
			}
		}
	}

	sort(collidingTiles, n);

	for (int i = 0; i < n; i++) {
		collidingTiles[i].tile->onCollision(player);
	}

}

void TileMap::sort(collidingTile* collidingTiles, int size) {
	bool trocou = true;
	while (trocou) {
		trocou = false;
		for (int i = 0; i < size - 1; i++) {
			if (collidingTiles[i].distanceToPlayer
					> collidingTiles[i + 1].distanceToPlayer) {
				trocou = true;
				collidingTile temp;
				temp = collidingTiles[i];
				collidingTiles[i] = collidingTiles[i + 1];
				collidingTiles[i + 1] = temp;
			}
		}
	}
}

void TileMap::setPosition(Vector2 newPosition) {
	this->position = newPosition;
}

void TileMap::positionToIndex(Vector2 position, int* i, int* j) {
	*i = (int) floor(position.y / tileHeight);
	*j = (int) floor(position.x / tileWidth);
}
