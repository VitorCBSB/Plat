/*
 * Camera.cpp
 *
 *  Created on: 22/12/2013
 *      Author: vitor
 */

#include "Camera.h"

Camera::Camera(Vector2 position) : position(position) {
}

int Camera::getX() {
	return position.x;
}

int Camera::getY() {
	return position.y;
}
