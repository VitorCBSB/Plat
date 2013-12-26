/*
 * Game.cpp
 *
 *  Created on: 21/12/2013
 *      Author: vitor
 */

#include "Game.h"

Game::Game() {
	SDLBase::initializeSDL();
}

Game::~Game() {
	SDLBase::finalizeSDL();
}

int Game::run() {
	TestObjPtr testObj(
			new TestObj(SpritePtr(new Sprite("../img/wow.png")),
					Vector2(400, 300)));
	TileMapPtr tileMap(
			new TileMap(std::string("../maps/testMap.map"),
					std::string("../tiles/Tileset.png"), TILE_WIDTH,
					TILE_HEIGHT));
	CameraPtr camera(new Camera());
	double dt = 1.0 / FPS;

	while (!InputManager::get()->QuitGame()) {
		InputManager::get()->update();

		camera->update(dt);
		testObj->update(dt);
		tileMap->render(camera->getX(), camera->getY());
		testObj->render(camera->getX(), camera->getY());
		SDLBase::updateScreen();
		SDLBase::clearScreen();
		SDL_Delay((1.0 / FPS) * 1000);

	}

	return 0;
}
