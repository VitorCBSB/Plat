/*
 * Rect.cpp
 *
 *  Created on: 22/12/2013
 *      Author: vitor
 */

#include "Rect.h"

Rect::Rect(Vector2 position, float w, float h) :
		position(position), w(w), h(h) {
}

float Rect::area() {
	return w * h;
}

bool Rect::collidesWith(Rect other) {
	float diffX = (this->position.x - this->w / 2)
			- (other.position.x - other.w / 2);
	float diffY = (this->position.y - this->h / 2)
			- (other.position.y - other.h / 2);

	if (diffX > other.w || -diffX > this->w) {
		return false;
	}
	if (diffY > other.h || -diffY > this->h) {
		return false;
	}

	return true;

}

Vector2 Rect::intersection(Rect other) {
	float minDistanceX = this->w / 2 + other.w / 2;
	float minDistanceY = this->h / 2 + other.h / 2;

	float distanceX = this->position.x - other.position.x;
	float distanceY = this->position.y - other.position.y;

	if (fabs(distanceX) > minDistanceX || fabs(distanceY) > minDistanceY) {
		return Vector2(0, 0);
	}

	distanceX =
			distanceX > 0 ?
					minDistanceX - distanceX : -minDistanceX - distanceX;
	distanceY =
			distanceY > 0 ?
					minDistanceY - distanceY : -minDistanceY - distanceY;

	return Vector2(distanceX, distanceY);
}
