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

	while (!InputManager::get()->QuitGame()) {
		InputManager::get()->update();
		testObj->update(1 / FPS);
		testObj->render(0, 0);
		SDLBase::updateScreen();
		SDLBase::clearScreen();
		SDL_Delay(1 / FPS);
	}

	return 0;
}
