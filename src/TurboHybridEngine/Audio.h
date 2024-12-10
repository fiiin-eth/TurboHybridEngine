#pragma once

#include <AL/al.h>
#include <AL/alc.h>

namespace TurboHybridEngine {

	struct Audio {

	public:

		Audio();
		~Audio();

	private:

		ALCcontext* m_context;
		ALCdevice* m_device;
	};

}