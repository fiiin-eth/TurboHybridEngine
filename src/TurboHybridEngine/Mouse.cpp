#include "Mouse.h"

namespace TurboHybridEngine {

	Mouse::Mouse() {
	}

	void Mouse::Update() {
		mouseDown.clear();
		mouseUp.clear();
	}

	bool Mouse::IsMouse(int _mouse) {
		for (int i = 0; i < mouse.size(); ++i) {
			if (mouse[i] == _mouse) {
				return true;
			}
		}
		return false;
	}

	bool Mouse::IsMouseDown(int _mouse) {
		for (int i = 0; i < mouseDown.size(); ++i) {
			if (mouseDown[i] == _mouse) {
				return true;
			}
		}
		return false;
	}

	bool Mouse::IsMouseUp(int _mouse) {
		for (int i = 0; i < mouseUp.size(); ++i) {
			if (mouseUp[i] == _mouse) {
				return true;
			}
		}
		return false;
	}

}