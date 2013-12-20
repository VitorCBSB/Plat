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
	SDL_Texture* imagem;
	SDL_Rect dst;
	SDLBase::inicializaSDL();

	dst.x = 0;
	dst.y = 0;

	imagem = SDLBase::loadImage(std::string("../img/teste.jpg"));
	SDL_QueryTexture(imagem, NULL, NULL, &dst.w, &dst.h);
	SDLBase::renderTexture(imagem, NULL, &dst);
	SDLBase::atualizarTela();
	SDL_Delay(5000);

	SDL_DestroyTexture(imagem);
	SDLBase::finalizaSDL();
	return 0;
}

