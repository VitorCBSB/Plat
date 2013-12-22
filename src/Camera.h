/*
 * Camera.h
 *
 *  Created on: 22/12/2013
 *      Author: vitor
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "Vector2.h"

class Camera {
private:
	Vector2 position;

public:
	Camera(Vector2 position);
	int getX();
	int getY();
};

#endif /* CAMERA_H_ */
