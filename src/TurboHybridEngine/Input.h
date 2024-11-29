#pragma once

#include "Keyboard.h"

#include <memory>

namespace TurboHybridEngine {

	class Input {

	public:

		Input();

		bool Update();

		std::shared_ptr<Keyboard> GetKeyboard() { return m_keyboard; }

	private:
		std::shared_ptr<Keyboard> m_keyboard;

	};

}