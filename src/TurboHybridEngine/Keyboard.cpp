#include "Keyboard.h"

namespace TurboHybridEngine {

	Keyboard::Keyboard() {
	}

	void Keyboard::Update() {
		keysDown.clear();
		keysUp.clear();
	}

	bool Keyboard::IsKey(int _key) {
		for (int i = 0; i < keys.size(); ++i) {
			if (keys[i] == _key) {
				return true;
			}
		}
		return false;
	}

	bool Keyboard::IsKeyDown(int _key) {
		printf("keysDown size: %d\n", keysDown.size());
		for (int i = 0; i < keysDown.size(); ++i) {
			if (keysDown[i] == _key) {
				return true;
			}
		}
		return false;
	}

	bool Keyboard::IsKeyUp(int _key) {
		for (int i = 0; i < keysUp.size(); ++i) {
			if (keysUp[i] == _key) {
				return true;
			}
		}
		return false;
	}

}