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
#include <memory>

class TestObj: public GameObject {
private:
	SpritePtr sprite;
	Vector2 position;
public:
	TestObj(SpritePtr sprite, Vector2 position);
	virtual ~TestObj();

	void update(double dt);
	void render(float cameraX = 0, float cameraY = 0);
};

#endif /* TESTOBJ_H_ */
