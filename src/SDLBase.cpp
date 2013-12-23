/*
 * abc.cpp
 *
 *  Created on: 06/04/2013
 *      Author: Vitor
 */

#include "SDLBase.h"

SDL_Renderer* SDLBase::screenRenderer;
SDL_Window* SDLBase::screen;

int SDLBase::initializeSDL() {

	if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1) {
		fprintf(stderr, "Erro na inicializacao da SDL.\n");
		exit(1);
	}

	screen = SDL_CreateWindow("Plat", 500, 500, 800, 600, SDL_WINDOW_SHOWN);
	screenRenderer = SDL_CreateRenderer(screen, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	TTF_Init();
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,
			MIX_DEFAULT_CHANNELS, 1024);

	if (screenRenderer == NULL) {
		fprintf(stderr, "Nao consegui carregar a tela\n");
		exit(1);
	}

	return 0;

}

void SDLBase::finalizeSDL() {
	SDL_DestroyRenderer(screenRenderer);
	SDL_DestroyWindow(screen);
	TTF_Quit();
	Mix_CloseAudio();
	SDL_Quit();
}

SDL_Texture* SDLBase::loadImage(std::string fileName) {
	SDL_Texture* texture;
	if ((texture = IMG_LoadTexture(screenRenderer, fileName.c_str())) == NULL) {
		fprintf(stderr, "Nao consegui carregar a imagem %s.\n",
				fileName.c_str());
		exit(1);
	}
	return texture;
}

void SDLBase::renderTexture(SDL_Texture* texture, SDL_Rect* clip,
		SDL_Rect* dst) {

	if (SDL_RenderCopy(screenRenderer, texture, clip, dst) == -1) {
		fprintf(stderr, "Nao consegui blitar uma texture de dimensoes: %dx%d",
				clip->w, clip->h);
		exit(1);
	}

}

void SDLBase::clearScreen() {
	SDL_RenderClear(screenRenderer);
}

void SDLBase::updateScreen() {
	SDL_RenderPresent(screenRenderer);
}

