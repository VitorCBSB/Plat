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
	Sprite* sprite;
	Vector2 position;
public:
	TestObj(Sprite* sprite, Vector2 position);
	virtual ~TestObj();

	void update(double dt);
	void render(float cameraX, float cameraY);
};

#endif /* TESTOBJ_H_ */
