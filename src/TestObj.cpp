/*
 * TestObj.cpp
 *
 *  Created on: 22/12/2013
 *      Author: vitor
 */

#include "TestObj.h"

TestObj::TestObj(SpritePtr sprite, Vector2 position) :
		GameObject(), sprite(sprite), rect(position, 0, 0), acceleration(
				Vector2(0, 0)), velocity(Vector2(0, 0)) {

}

TestObj::~TestObj() {
}

void TestObj::update(double dt) {
	acceleration = Vector2(0, 0);

	if (InputManager::get()->isKeyHeld(SDL_SCANCODE_W)) {
		acceleration = acceleration + Vector2(0, -ACCELERATION);
	}
	if (InputManager::get()->isKeyHeld(SDL_SCANCODE_A)) {
		acceleration = acceleration + Vector2(-ACCELERATION, 0);
	}
	if (InputManager::get()->isKeyHeld(SDL_SCANCODE_S)) {
		acceleration = acceleration + Vector2(0, ACCELERATION);
	}
	if (InputManager::get()->isKeyHeld(SDL_SCANCODE_D)) {
		acceleration = acceleration + Vector2(ACCELERATION, 0);
	}

	velocity = velocity + (acceleration * dt);
	rect.position = rect.position + (velocity * dt);

	velocity = velocity * (1.0 - std::min(FRICTION * dt, 1.0));
}

void TestObj::render(float cameraX, float cameraY) {
	sprite->render(rect.position.x - cameraX, rect.position.y - cameraY);
}
