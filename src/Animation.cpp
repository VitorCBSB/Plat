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
				frameHeight), frameTime(frameTime), looping(looping) {

}

Animation::~Animation() {
	// TODO Auto-generated destructor stub
}

void Animation::update(double dt) {

}
