/*
 * Rect.cpp
 *
 *  Created on: 22/12/2013
 *      Author: vitor
 */

#include "Rect.h"

Rect::Rect(float x, float y, float w, float h) : x(x), y(y), w(w), h(h){
}

float Rect::area() {
	return w * h;
}
