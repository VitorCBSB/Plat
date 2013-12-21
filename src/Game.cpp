/*
 * Game.cpp
 *
 *  Created on: 21/12/2013
 *      Author: vitor
 */

#include "Game.h"

Game::Game() {
	SDLBase::inicializaSDL();
}

Game::~Game() {
	SDLBase::finalizaSDL();
}

int Game::run() {
	std::auto_ptr<Sprite> sprite(new Sprite("../img/teste.jpg"));

	while(!SDL_QuitRequested()) {
		sprite->render();
		SDLBase::atualizarTela();
		SDLBase::limparTela();
		SDL_Delay(16);
	}

	return 0;
}
