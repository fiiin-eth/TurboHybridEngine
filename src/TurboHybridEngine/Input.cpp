#pragma once
#include "Keyboard.h"
#include "Mouse.h"
#include "Input.h"

namespace TurboHybridEngine {

	Input::Input() {
		m_keyboard = std::make_shared<Keyboard>();
		m_mouse = std::make_shared<Mouse>();
	}

	bool Input::Update() {
		m_keyboard->Update();
		m_mouse->Update();

		SDL_Event event = {};

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return false;
			}

			else if (event.type == SDL_KEYDOWN) {
			
				m_keyboard->keys.push_back(event.key.keysym.sym);
				m_keyboard->keysDown.push_back(event.key.keysym.sym);
			}

			else if (event.type == SDL_KEYUP) {
				m_keyboard->KeyReleased(event.key.keysym.sym);
				m_keyboard->keysUp.push_back(event.key.keysym.sym);
			}

			else if (event.type == SDL_MOUSEBUTTONDOWN) {
				m_mouse->mouse.push_back(event.button.button);
				m_mouse->mouseDown.push_back(event.button.button);
			}
			else if (event.type = SDL_MOUSEBUTTONUP) {
				m_mouse->MouseReleased(event.button.button);
				m_mouse->mouseUp.push_back(event.button.button);
			}

		}


		return true;
	}

	std::shared_ptr<Keyboard> Input::GetKeyboard() const {
		return m_keyboard;
	}

	std::shared_ptr<Mouse> Input::GetMouse() const {
		return m_mouse;
	}

}