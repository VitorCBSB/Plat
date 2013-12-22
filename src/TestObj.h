/*
 * TestObj.h
 *
 *  Created on: 22/12/2013
 *      Author: vitor
 */

#ifndef TESTOBJ_H_
#define TESTOBJ_H_

#include "GameObject.h"
#include "Sprite.h"
#include "Vector2.h"
#include "InputManager.h"
#include "SDLBase.h"
#include <math.h>

#define MAX_SPEED 50.0

class TestObj: public GameObject {
private:
	SpritePtr sprite;
	Vector2 position;
	Vector2 acceleration;
	Vector2 velocity;

public:
	TestObj(SpritePtr sprite, Vector2 position);
	virtual ~TestObj();

	void update(double dt);
	void render(float cameraX = 0, float cameraY = 0);
};

#endif /* TESTOBJ_H_ */
