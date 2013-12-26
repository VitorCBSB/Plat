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
						new TileSet(tileSetFileName, tileWidth, tileHeight))), tileWidth(
				tileWidth), tileHeight(tileHeight), position(Vector2(0, 0)) {
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

	for (int k = 0; k < LAYERS; k++) {
		for (int i = 0; i < LINES; i++) {
			for (int j = 0; j < COLUMNS; j++) {
				fscanf(fp, "%d", &tileIndex);
				if (k == LAYERS - 1) { // Se for a camada mais proxima da tela
					tileMatrix[k][i][j] = TilePtr(
							new TileSolid(
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
	for (int k = 0; k < LAYERS; k++) {
		for (int i = 0; i < LINES; i++) {
			for (int j = 0; j < COLUMNS; j++) {
				tileMatrix[k][i][j]->render(cameraX, cameraY);
			}
		}
	}
}

void TileMap::setPosition(Vector2 newPosition) {
	this->position = newPosition;
}
