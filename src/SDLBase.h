/*
 * SDLBase.h
 *
 *  Created on: 06/04/2013
 *      Author: Vitor
 */

#ifndef SDLBASE_H_
#define SDLBASE_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL2/SDL_mixer.h"
#include <stdlib.h>
#include <string>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

class SDLBase {
private:
	static SDL_Renderer* screenRenderer;
	static SDL_Window* screen;

public:

	enum {
		STATENOCHANGE = 0,
		STATESPLASH,
		STATEGAME,
		STATEWIN,
		STATELOSE,
		STATEQUIT,
		STATEDESTROY,
		STATEEDITOR,
		STATEPAUSE,
		STATEMENU
	};

	static int initializeSDL();

	static void finalizeSDL();

	static SDL_Texture* loadImage(std::string fileName);

//	static SDL_Surface* clip(SDL_Surface* original, SDL_Rect* clip);

//	static SDL_Surface* rotoZoom(SDL_Surface* surface, float angle,
//			float scaleX, float scaleY);

	static void renderTexture(SDL_Texture* texture, SDL_Rect* clip,
			SDL_Rect* dst);

//	static void drawLine(int x1, int y1, int x2, int y2, int rgb, int spacing);

	static void clearScreen();

	static void updateScreen();

};

#endif /* SDLBASE_H_ */
