#pragma once

#include <SDL2/SDL.h>

#include <vector>

namespace TurboHybridEngine {

	class Input;

	class Keyboard {

	public:

		Keyboard();

		void Update();

		bool IsKey(int _key);
		bool IsKeyDown(int _key);
		bool IsKeyUp(int _key);

	private:
		friend class Input;

		void KeyReleased(int _key) {

			for (int i = 0; i < keys.size(); ++i) {
				if (keys[i] == _key) {
					keys.erase(keys.begin() + i);
					--i;
				}
			}
		}

		std::vector<int> keys;
		std::vector<int> keysDown;
		std::vector<int> keysUp;
	};

}