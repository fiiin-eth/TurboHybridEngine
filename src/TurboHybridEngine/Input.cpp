#pragma once
#include "Keyboard.h"
#include "Input.h"

namespace TurboHybridEngine {

	Input::Input() {
		m_keyboard = std::make_shared<Keyboard>();
	}

	bool Input::Update() {
		m_keyboard->Update();


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


		}


		return true;
	}

	std::shared_ptr<Keyboard> Input::GetKeyboard() const {
		return m_keyboard;
	}

}