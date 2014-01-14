/*
 * Animation.h
 *
 *  Created on: 14/01/2014
 *      Author: vitor
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "Sprite.h"
#include <tr1/memory>

class Animation {
private:
	SpritePtr animationSheet;
	int frameWidth;
	int frameHeight;
	int frameTime;
	bool looping;

public:
	Animation(SpritePtr animationSheet, int frameWidth, int frameHeight,
			int frameTime, bool looping);
	virtual ~Animation();

	void update(double dt);

	int getFrameHeight() const {
		return frameHeight;
	}

	void setFrameHeight(int frameHeight) {
		this->frameHeight = frameHeight;
	}

	int getFrameTime() const {
		return frameTime;
	}

	void setFrameTime(int frameTime) {
		this->frameTime = frameTime;
	}

	int getFrameWidth() const {
		return frameWidth;
	}

	void setFrameWidth(int frameWidth) {
		this->frameWidth = frameWidth;
	}
};

typedef std::tr1::shared_ptr<Animation> AnimationPtr;

#endif /* ANIMATION_H_ */
