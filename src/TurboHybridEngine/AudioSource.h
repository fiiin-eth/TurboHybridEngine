#pragma once

#include "Component.h"
#include "Sound.h"

#include <AL/al.h>
#include <AL/alc.h>

#include <exception>
#include <vector>
#include <string>

namespace TurboHybridEngine {

	struct AudioSource : public Component {
	public:
		AudioSource() { alGenSources(1, &m_sourceId); }
		~AudioSource();

		void SetSound(std::shared_ptr<Sound> _sound) { m_sound = _sound; alSourcei(m_sourceId, AL_BUFFER, m_sound->m_bufferId); }

		bool IsPlaying();

		void OnTick();

		void Play();

	private:
		std::shared_ptr<Sound> m_sound = nullptr;

		ALuint m_bufferId = 0;
		ALuint m_sourceId = 0;
	};

}