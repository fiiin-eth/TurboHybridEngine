#include "AudioSource.h"
#include "Sound.h"
#include "Transform.h"

namespace TurboHybridEngine {


	bool AudioSource::IsPlaying() {

		int state = 0;
		alGetSourcei(m_sourceId, AL_SOURCE_STATE, &state);
		if (state == AL_PLAYING) {
			return true;
		}
		return false;

	}

	void AudioSource::OnTick() {

		alSource3f(m_sourceId, AL_POSITION, get_transform()->get_position().x, get_transform()->get_position().y, get_transform()->get_position().z);

		if (!IsPlaying()) {
			Play();
		}

	}

	void AudioSource::Play() {
		if(m_sound) {	
			alSourcePlay(m_sourceId);
			printf("audio path");
			printf(m_sound->get_path().c_str());
		}
		else {
			printf("Failed to play audio\n");
		}
	}

	AudioSource::~AudioSource() {
		alDeleteSources(1, &m_sourceId);
	}

}