/*
 * Rect.h
 *
 *  Created on: 22/12/2013
 *      Author: vitor
 */

#ifndef RECT_H_
#define RECT_H_

#include "Vector2.h"

class Rect {
public:
	Vector2 position;
	float w, h;

	Rect(Vector2 position, float w, float h);

	float area();
};

#endif /* RECT_H_ */
