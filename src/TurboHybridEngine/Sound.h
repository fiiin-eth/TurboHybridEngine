#pragma once

#include <AL/al.h>
#include <AL/alc.h>

#include <stdexcept>
#include <vector>
#include <string>

#include "Resource.h"
#include "stb_vorbis.c"

namespace TurboHybridEngine {

	struct AudioSource;

	struct Sound : public Resource {
	public:

		void OnLoad();
	private:

		friend class AudioSource;

		ALuint m_bufferId = 0;
		ALenum m_format = 0;
		ALsizei m_frequency = 0;
	};

}