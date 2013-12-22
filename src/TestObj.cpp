/*
 * TestObj.cpp
 *
 *  Created on: 22/12/2013
 *      Author: vitor
 */

#include "TestObj.h"

TestObj::TestObj(SpritePtr sprite, Vector2 position) :
		sprite(sprite), position(position) {

}

TestObj::~TestObj() {
}

void TestObj::update(double dt) {

}

void TestObj::render(float cameraX, float cameraY) {
	sprite->render(position.x - cameraX, position.y - cameraY);
}
