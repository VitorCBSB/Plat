/*
 * InputManager.cpp
 *
 *  Created on: 22/12/2013
 *      Author: vitor
 */

#include "InputManager.h"

InputManager::InputManager() :
		mouseState(0), keyStates(NULL), quitGame(false), mouseX(0), mouseY(0) {
}

InputManager::~InputManager() {
}

void InputManager::initKeyboard() {
	for (int i = 0; i < SDL_NUM_SCANCODES; i++) {
		keyDown[i] = keyUp[i] = 0;
	}
}

void InputManager::initMouse() {
	for (int i = 0; i < N_MOUSE_BUTTONS; i++) {
		mouseDown[i] = mouseUp[i] = 0;
	}
}

void InputManager::update() {
	SDL_Event event;

	initKeyboard();
	initMouse();

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			keyDown[event.key.keysym.scancode] = true;
			break;
		case SDL_KEYUP:
			keyUp[event.key.keysym.scancode] = true;
			break;
		case SDL_MOUSEBUTTONDOWN:
			mouseDown[event.button.button] = true;
			break;
		case SDL_MOUSEBUTTONUP:
			mouseUp[event.button.button] = true;
			break;
		}
	}
}
