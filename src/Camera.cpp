/*
 * Camera.cpp
 *
 *  Created on: 22/12/2013
 *      Author: vitor
 */

#include "Camera.h"

Camera* Camera::instance = NULL;

Camera::Camera() :
		position(Vector2(0, 0)), velocity(Vector2(0, 0)) {
}

void Camera::update(double dt) {
	position = position + (velocity * dt);
}

int Camera::getX() {
	return position.x;
}

int Camera::getY() {
	return position.y;
}

void Camera::setX(int x) {
	position.x = x;
}

void Camera::setY(int y) {
	position.y = y;
}

void Camera::setVelocity(Vector2 velocity) {
	this->velocity = velocity;
}
