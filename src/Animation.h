/*
 * Animation.h
 *
 *  Created on: 14/01/2014
 *      Author: vitor
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "Sprite.h"

class Animation {
private:
	SpritePtr animationSheet;

public:
	Animation(SpritePtr animationSheet);
	virtual ~Animation();

	void update(double dt);
};

#endif /* ANIMATION_H_ */
