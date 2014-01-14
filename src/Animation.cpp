/*
 * Animation.cpp
 *
 *  Created on: 14/01/2014
 *      Author: vitor
 */

#include "Animation.h"

Animation::Animation(SpritePtr animationSheet, int frameWidth, int frameHeight,
		int frameTime, bool looping) :
		animationSheet(animationSheet), frameWidth(frameWidth), frameHeight(
				frameHeight), frameTime(frameTime), currentFrame(0), looping(
				looping) {
	timer.start(frameTime);
}

Animation::~Animation() {
}

void Animation::update() {
	timer.update();
	if (timer.isDone()) {
		timer.start(frameTime);
		currentFrame++;
		currentFrame %= (animationSheet->getWidth() / frameWidth);
	}
	SDL_Rect clip;
	clip.x = currentFrame * frameWidth;
	clip.y = 0;
	clip.w = frameWidth;
	clip.h = frameHeight;

	animationSheet->clipTexture(clip);
}

void Animation::render(int x, int y, bool center) {
	animationSheet->render(x, y, center);
}
