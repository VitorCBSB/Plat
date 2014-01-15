/*
 * Camera.h
 *
 *  Created on: 22/12/2013
 *      Author: vitor
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "Vector2.h"
#include "InputManager.h"
#include "SDLBase.h"
#include <stdlib.h>
#include <tr1/memory>

#define SPEED 500

class Camera {
public:
	Vector2 position;

	Camera();
	void update(double dt);
	float getX();
	float getY();
};

typedef std::tr1::shared_ptr<Camera> CameraPtr;

#endif /* CAMERA_H_ */
