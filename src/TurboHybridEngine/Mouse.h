#pragma once

#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <vector>

namespace TurboHybridEngine {

	struct Input;

	struct Mouse {

	public:

		Mouse();

		void Update();

		bool IsMouse(int _mouse);
		bool IsMouseDown(int _mouse);
		bool IsMouseUp(int _mouse);

		int get_xPosition() { return m_xPos; }
		int get_yPosition() { return m_yPos; }

	private:
		friend struct Input;

		void MouseReleased(int _mouse) {

			for (int i = 0; i < mouse.size(); ++i) {
				if (mouse[i] == _mouse) {
					mouse.erase(mouse.begin() + i);
					break;
				}
			}
		}

		int m_xPos = 0;
		int m_yPos = 0;

		std::vector<int> mouse;
		std::vector<int> mouseDown;
		std::vector<int> mouseUp;
	};

}