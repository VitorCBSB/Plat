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
#include "Rect.h"
#include "InputManager.h"
#include "SDLBase.h"
#include <math.h>
#include <tr1/memory>

#define MAX_SPEED 500.0
#define ACCELERATION 1000.0
#define FRICTION 3.5

class TestObj: public GameObject {
private:
	SpritePtr sprite;
	Rect rect;
	Vector2 acceleration;
	Vector2 velocity;

public:
	TestObj(SpritePtr sprite, Vector2 position);
	virtual ~TestObj();

	void update(double dt);
	void render(float cameraX = 0, float cameraY = 0);
};

typedef std::tr1::shared_ptr<TestObj> TestObjPtr;

#endif /* TESTOBJ_H_ */
