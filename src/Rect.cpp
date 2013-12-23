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
