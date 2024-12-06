#pragma once

#include <memory>

namespace TurboHybridEngine {

	class Keyboard;
	struct Core;

	class Input {

	public:

		Input();

		bool Update();

		std::shared_ptr<Keyboard> GetKeyboard() const;

	private:
		friend struct Core;
		std::shared_ptr<Keyboard> m_keyboard;

	};

}