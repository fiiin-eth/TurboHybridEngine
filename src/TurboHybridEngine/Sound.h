#pragma once

#include <AL/al.h>
#include <AL/alc.h>

#include <stdexcept>
#include <vector>
#include <string>

#include "stb_vorbis.c"

namespace TurboHybridEngine {

	struct Audio {

		Audio();
		~Audio();

		void load_ogg(const std::string& _path, std::vector<unsigned char>& _buffer,
			ALenum& _format, ALsizei& _freq);
	};

}