/*
 * TestObj.cpp
 *
 *  Created on: 22/12/2013
 *      Author: vitor
 */

#include "TestObj.h"

TestObj::TestObj(SpritePtr sprite, Rect rect) :
		GameObject(), sprite(sprite), onGround(true), rect(rect), acceleration(
				Vector2(0, 0)), velocity(Vector2(0, 0)) {
}

TestObj::~TestObj() {
}

void TestObj::update(double dt) {
	acceleration = Vector2(0, 0);

	if (InputManager::get()->isKeyHeld(SDL_SCANCODE_S)) {
		acceleration += Vector2(0, ACCELERATION);
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
}

void TestObj::render(float cameraX, float cameraY) {
	sprite->render(rect.position.x - cameraX, rect.position.y - cameraY);
}
