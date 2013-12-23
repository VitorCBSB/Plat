/*
 * Sprite.h
 *
 *  Created on: 21/12/2013
 *      Author: vitor
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include "SDLBase.h"
#include <string>
#include <tr1/memory>

class Sprite {
private:
	SDL_Texture* texture;
	SDL_Rect clip;
	bool hidden;

public:
	Sprite(std::string fileName);
	Sprite(std::string fileName, bool hidden);
	virtual ~Sprite();

	void clipTexture(SDL_Rect newClip);
	void render(int x = 0, int y = 0, bool center = true);

	int getHeight();
	int getWidth();
	int getHeightClipped();
	int getWidthClipped();
};

typedef std::tr1::shared_ptr<Sprite> SpritePtr;

#endif /* SPRITE_H_ */
