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
		acceleration = acceleration + Vector2(0, -10);
	}
	if (InputManager::get()->isKeyHeld(SDL_SCANCODE_A)) {
		acceleration = acceleration + Vector2(-10, 0);
	}
	if (InputManager::get()->isKeyHeld(SDL_SCANCODE_S)) {
		acceleration = acceleration + Vector2(0, 10);
	}
	if (InputManager::get()->isKeyHeld(SDL_SCANCODE_D)) {
		acceleration = acceleration + Vector2(10, 0);
	}

	velocity = velocity + (acceleration * dt);
	if (velocity.x > MAX_SPEED) {
		velocity.x = MAX_SPEED;
	}
	if (velocity.x < -MAX_SPEED) {
		velocity.x = -MAX_SPEED;
	}
	if (velocity.y > MAX_SPEED) {
		velocity.y = MAX_SPEED;
	}
	if (velocity.y < -MAX_SPEED) {
		velocity.y = -MAX_SPEED;
	}

	rect.position = rect.position + velocity;
}

void TestObj::render(float cameraX, float cameraY) {
	sprite->render(rect.position.x - cameraX, rect.position.y - cameraY);
}
