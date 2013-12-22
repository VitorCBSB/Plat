/*
 * Game.h
 *
 *  Created on: 21/12/2013
 *      Author: vitor
 */

#ifndef GAME_H_
#define GAME_H_

#define FPS 60.0

#include "SDLBase.h"
#include "Sprite.h"
#include "TestObj.h"
#include "InputManager.h"
#include <string>

class Game {
public:
	Game();
	virtual ~Game();

	int run();
};

#endif /* GAME_H_ */
