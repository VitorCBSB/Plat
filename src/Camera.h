/*
 * Camera.h
 *
 *  Created on: 22/12/2013
 *      Author: vitor
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "Vector2.h"
#include <stdlib.h>

class Camera {
private:
	Vector2 position;
	Vector2 velocity;
	static Camera* instance;
	Camera();

public:
	Camera* get() {
		if (instance) {
			return instance;
		}
		return new Camera();
	}
	void update(double dt);
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	void setVelocity(Vector2 velocity);
};

#endif /* CAMERA_H_ */
