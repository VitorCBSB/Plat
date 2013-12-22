/*
 * GameObject.h
 *
 *  Created on: 22/12/2013
 *      Author: vitor
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Camera.h"

class GameObject {
public:
	GameObject();
	virtual ~GameObject();

	virtual void render(float cameraX = 0, float cameraY = 0) = 0;
	virtual void update(double dt) = 0;
};

#endif /* GAMEOBJECT_H_ */
