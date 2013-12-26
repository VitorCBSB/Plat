/*
 * Camera.cpp
 *
 *  Created on: 22/12/2013
 *      Author: vitor
 */

#include "Camera.h"

Camera::Camera() :
		position(Vector2(0, 0)), velocity(Vector2(0, 0)) {
}

void Camera::update(double dt) {
	velocity = Vector2(0, 0);
	if (InputManager::get()->isKeyHeld(SDL_SCANCODE_LEFT)) {
		velocity = velocity + Vector2(-SPEED, 0);
	}
	if (InputManager::get()->isKeyHeld(SDL_SCANCODE_DOWN)) {
		velocity = velocity + Vector2(0, SPEED);
	}
	if (InputManager::get()->isKeyHeld(SDL_SCANCODE_RIGHT)) {
		velocity = velocity + Vector2(SPEED, 0);
	}
	if (InputManager::get()->isKeyHeld(SDL_SCANCODE_UP)) {
		velocity = velocity + Vector2(0, -SPEED);
	}
	position = position + (velocity * dt);
}

float Camera::getX() {
	return position.x;
}

float Camera::getY() {
	return position.y;
}
