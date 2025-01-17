#pragma once

#include <memory>

namespace TurboHybridEngine {

	struct Keyboard;
	struct Mouse;

	struct Core;

	struct Input {

	public:

		Input();

		bool Update();

		std::shared_ptr<Keyboard> GetKeyboard() const;
		std::shared_ptr<Mouse> GetMouse() const;

	private:
		friend struct Core;
		std::shared_ptr<Keyboard> m_keyboard;
		std::shared_ptr<Mouse> m_mouse;

	};

}