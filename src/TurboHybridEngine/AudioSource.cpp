#include "AudioSource.h"
#include "Sound.h"

namespace TurboHybridEngine {

	AudioSource::AudioSource() {
		ALenum format = 0;
		ALsizei freq = 0;
		std::vector<unsigned char> bufferData;
		load_ogg("../assets/Audio/dixie_horn.ogg", bufferData, format, freq);

		ALuint bufferId = 0;
		alGenBuffers(1, &bufferId);

		alBufferData(bufferId, format, &bufferData.at(0),
			static_cast<ALsizei>(bufferData.size()), freq);
	}

	AudioSource::~AudioSource() {

	}

}