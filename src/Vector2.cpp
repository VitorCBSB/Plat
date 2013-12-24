/*
 * Vector2.cpp
 *
 *  Created on: 21/12/2013
 *      Author: vitor
 */

#include "Vector2.h"

Vector2::Vector2(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2::~Vector2() {
}

Vector2 Vector2::operator +(Vector2 other) {
	return Vector2(this->x + other.x, this->y + other.y);
}

Vector2 Vector2::operator -(Vector2 other) {
	return Vector2(this->x - other.x, this->y - other.y);
}

Vector2 Vector2::operator *(float scalar) {
	return Vector2(this->x * scalar, this->y * scalar);
}

float Vector2::operator *(Vector2 other) {
	return this->x * other.x + this->y * other.y;
}

float Vector2::length() {
	return sqrt(this->x * this->x + this->y * this->y);
}

Vector2 Vector2::normalize() {
	float vecLength = length();
	return Vector2(this->x / vecLength, this->y / vecLength);
}

Vector2 Vector2::rotate(float angleInDegrees) {
	float angleInRadians = angleInDegrees * M_PI / 180;

	return Vector2(
			this->x * cos(angleInRadians) - this->y * sin(angleInRadians),
			this->x * sin(angleInRadians) + this->y * cos(angleInRadians));
}

Vector2 Vector2::normalVector() {
	return rotate(90);
}

