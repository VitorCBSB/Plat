/*
 * TestObj.cpp
 *
 *  Created on: 22/12/2013
 *      Author: vitor
 */

#include "TestObj.h"

TestObj::TestObj(AnimationPtr animation, Rect rect) :
		GameObject(), animation(animation), onGround(true), rect(rect), acceleration(
				Vector2(0, 0)), velocity(Vector2(0, 0)) {
}

TestObj::~TestObj() {
}

void TestObj::update(double dt) {
	acceleration = Vector2(0, 0);

	if (InputManager::get()->isKeyHeld(SDL_SCANCODE_A)) {
		acceleration += Vector2(-ACCELERATION, 0);
	}
	if (InputManager::get()->isKeyHeld(SDL_SCANCODE_D)) {
		acceleration += Vector2(ACCELERATION, 0);
	}
	if (InputManager::get()->isKeyDown(SDL_SCANCODE_SPACE) && onGround) {
		acceleration += Vector2(0, -JUMP);
	}
	// Pulo de tamanho variavel
	if (InputManager::get()->isKeyUp(SDL_SCANCODE_SPACE)) {
		if (velocity.y < -JUMP_SPEED_CUT) {
			velocity.y = -JUMP_SPEED_CUT;
		}
	}

	Vector2 gravity = Vector2(0, GRAVITY);
	Vector2 totalForce = gravity + acceleration;

	velocity += (totalForce * dt);
	rect.position += (velocity * dt);

	velocity *= (1.0 - std::min(FRICTION * dt, 1.0));

	animation->setFrameTime(MAX_ANIMATION_TIME - fabs(velocity.x));
	animation->update();

}

void TestObj::render(float cameraX, float cameraY) {
	animation->render(rect.position.x - cameraX, rect.position.y - cameraY);
}
