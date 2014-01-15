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
			new TestObj(
					AnimationPtr(
							new Animation(
									SpritePtr(
											new Sprite(
													"../img/testeAnimacao.png")),
									64, 64, 200, true)),
					Rect(Vector2(400, 300), 64, 64)));
	TileMapPtr tileMap(
			new TileMap(std::string("../maps/testMap.map"),
					std::string("../tiles/Tileset.png"), TILE_WIDTH,
					TILE_HEIGHT));
	CameraPtr camera(new Camera());
	double dt = 1.0 / FPS;

	while (!InputManager::get()->QuitGame()) {
		InputManager::get()->update();

		testObj->update(dt);
		tileMap->checkCollision(testObj);
		camera->position = testObj->rect.position;
		camera->position.x -= WINDOW_WIDTH / 2;
		camera->position.y -= WINDOW_HEIGHT / 2;
		tileMap->render(camera->position.x, camera->position.y);
		testObj->render(camera->position.x, camera->position.y);
		SDLBase::updateScreen();
		SDLBase::clearScreen();
		SDL_Delay((1.0 / FPS) * 1000);

	}

	return 0;
}
