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
	static Camera* instance;
	Camera();

public:
	Camera* getInstance() {
		if (instance) {
			return instance;
		}
		return new Camera();
	}
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
};

#endif /* CAMERA_H_ */
