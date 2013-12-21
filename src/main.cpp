/*
 * main.cpp
 *
 *  Created on: 20/12/2013
 *      Author: vitor
 */

#include <string>
#include <list>
#include <memory>
#include "SDLBase.h"
#include "Sprite.h"

int main() {
	SDL_Rect clip;

	clip.x = 0;
	clip.y = 0;
	clip.w = 50;
	clip.h = 50;

	SDLBase::inicializaSDL();
	std::auto_ptr<Sprite> sprite(new Sprite("../img/teste.jpg"));
	SDLBase::limparTela();

	sprite->clipTexture(clip);
	sprite->render(30, 0);

	SDLBase::atualizarTela();
	SDL_Delay(5000);

	SDLBase::finalizaSDL();
	return 0;
}

