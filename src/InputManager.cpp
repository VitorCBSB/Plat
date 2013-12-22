/*
 * InputManager.cpp
 *
 *  Created on: 22/12/2013
 *      Author: vitor
 */

#include "InputManager.h"

InputManager* InputManager::instance = NULL;

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

	keyStates = SDL_GetKeyboardState(NULL);
	mouseState = SDL_GetMouseState(&mouseX, &mouseY);

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			keyDown[event.key.keysym.sym] = true;
			break;
		case SDL_KEYUP:
			keyUp[event.key.keysym.sym] = true;
			break;
		case SDL_MOUSEBUTTONDOWN:
			mouseDown[event.button.button] = true;
			break;
		case SDL_MOUSEBUTTONUP:
			mouseUp[event.button.button] = true;
			break;
		case SDL_QUIT:
			quitGame = true;
			break;
		}
	}
}

bool InputManager::isKeyDown(int key) {
	return keyDown[key];
}

bool InputManager::isKeyUp(int key) {
	return keyUp[key];
}

bool InputManager::isKeyHeld(int key) {
	return keyStates[key];
}

bool InputManager::isMouseDown(int button) {
	return mouseDown[button];
}

bool InputManager::isMouseUp(int button) {
	return mouseUp[button];
}

bool InputManager::isMouseHeld(int button) {
	return mouseState & button;
}

int InputManager::mousePosX() {
	return mouseX;
}

int InputManager::mousePosY() {
	return mouseY;
}

bool InputManager::isMouseInside(SDL_Rect rect) {
	return mouseX >= rect.x && (mouseX <= rect.x + rect.w) && mouseY >= rect.y
			&& (mouseY <= rect.y + rect.h);
}

bool InputManager::QuitGame() {
	return quitGame;
}
