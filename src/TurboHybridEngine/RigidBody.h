#pragma once
#include "Component.h"

namespace TurboHybridEngine{

	struct Rigidbody : public Component
	{
		void on_tick();
	};
}