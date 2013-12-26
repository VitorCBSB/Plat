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

	if ((fp = fopen(fileName.c_str(), "r")) == NULL) {
		fprintf(stderr, "TileMap: arquivo %s nao pode ser aberto.",
				fileName.c_str());
		exit(1);
	}

	for (int k = 0; k < LAYERS; k++) {
		for (int i = 0; i < LINES; i++) {
			for (int j = 0; j < COLUMNS; j++) {
				fscanf(fp, "%d", &tileMatrix[k][i][j]);
			}
		}
	}

	fclose(fp);
}

void TileMap::render(float cameraX, float cameraY) {
	Vector2 actualPosition(position.x - cameraX, position.y - cameraY);

	for (int k = 0; k < LAYERS; k++) {
		for (int i = 0; i < LINES; i++) {
			for (int j = 0; j < COLUMNS; j++) {
				if (tileMatrix[k][i][j] != -1) {
					tileSet->render(tileMatrix[k][i][j],
							(j * tileWidth) + actualPosition.x,
							(i * tileHeight) + actualPosition.y);
				}
			}
		}
	}
}

void TileMap::setPosition(Vector2 newPosition) {
	this->position = newPosition;
}
