#pragma once

#include <SDL2/SDL.h>

#include <vector>

namespace TurboHybridEngine {

	class Input;

	struct Mouse {

	public:

		Mouse();

		void Update();

		bool IsMouse(int _mouse);
		bool IsMouseDown(int _mouse);
		bool IsMouseUp(int _mouse);

	private:
		friend class Input;

		void MouseReleased(int _mouse) {

			for (int i = 0; i < mouse.size(); ++i) {
				if (mouse[i] == _mouse) {
					mouse.erase(mouse.begin() + i);
					break;
				}
			}
		}

		std::vector<int> mouse;
		std::vector<int> mouseDown;
		std::vector<int> mouseUp;
	};

}