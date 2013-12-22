/*
 * TestObj.cpp
 *
 *  Created on: 22/12/2013
 *      Author: vitor
 */

#include "TestObj.h"

TestObj::TestObj(SpritePtr sprite, Vector2 position) :
		GameObject(), sprite(sprite), position(position), acceleration(
				Vector2(0, 0)), velocity(Vector2(0, 0)) {

}

TestObj::~TestObj() {
}

void TestObj::update(double dt) {
	acceleration = Vector2(0, 0);

	if (InputManager::get()->isKeyHeld(SDLK_w)) {
		acceleration = Vector2(0, -100);
	}
	if (InputManager::get()->isKeyHeld(SDLK_a)) {
		acceleration = Vector2(-100, 0);
	}
	if (InputManager::get()->isKeyHeld(SDLK_s)) {
		acceleration = Vector2(0, 100);
	}
	if (InputManager::get()->isKeyHeld(SDLK_d)) {
		acceleration = Vector2(100, 0);
	}

	velocity = velocity + (acceleration * dt);
	velocity.x = fmin(MAX_SPEED, velocity.x);
	velocity.y = fmin(MAX_SPEED, velocity.y);

	position = position + velocity;
}

void TestObj::render(float cameraX, float cameraY) {
	sprite->render(position.x - cameraX, position.y - cameraY);
}
