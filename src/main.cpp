/*
 * main.cpp
 *
 *  Created on: 20/12/2013
 *      Author: vitor
 */

#include <string>
#include <list>
#include "SDLBase.h"

int main() {
	std::string lol;
	SDL_Texture* imagem;
	SDLBase::inicializaSDL();

	imagem = SDLBase::loadImage(std::string("../img/teste.jpg"));
	SDLBase::renderTexture(imagem, NULL, NULL);
	SDL_Delay(2000);

	SDL_DestroyTexture(imagem);
	SDLBase::finalizaSDL();
	return 0;
}

