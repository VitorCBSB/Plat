/*
 * TestObj.h
 *
 *  Created on: 22/12/2013
 *      Author: vitor
 */

#ifndef TESTOBJ_H_
#define TESTOBJ_H_

#include "GameObject.h"
#include "Animation.h"
#include "Vector2.h"
#include "Rect.h"
#include "InputManager.h"
#include "SDLBase.h"
#include <math.h>
#include <tr1/memory>

#define MAX_SPEED 500.0
#define ACCELERATION 1000.0
#define GRAVITY 1200.0
#define JUMP 60000.0
#define JUMP_SPEED_CUT 380
#define FRICTION 3.5
#define MAX_ANIMATION_TIME 400

class TestObj: public GameObject {
private:
	AnimationPtr animation;
	bool onGround; // Tratamentos de colisão são responsáveis por tornar essa variável true

public:
	Rect rect;
	Vector2 acceleration;
	Vector2 velocity;

	TestObj(AnimationPtr animation, Rect rect);
	virtual ~TestObj();

	void update(double dt);
	void render(float cameraX = 0, float cameraY = 0);
	Rect getHitbox() {
		return rect;
	}
	void setPosition(Vector2 position) {
		rect.position = position;
	}
	Vector2 getPosition() {
		return rect.position;
	}
	void setOnGround(bool onGround) {
		this->onGround = onGround;
	}
};

typedef std::tr1::shared_ptr<TestObj> TestObjPtr;

#endif /* TESTOBJ_H_ */
