#include "Audio.h"

#include <stdexcept>

namespace TurboHybridEngine {

	Audio::Audio() {

        m_device = alcOpenDevice(NULL);

        if (!m_device)
        {
            throw std::runtime_error("Failed to open audio device");
        }

        m_context = alcCreateContext(m_device, NULL);

        if (!m_context)
        {
            alcCloseDevice(m_device);
            throw std::runtime_error("Failed to create audio context");
        }

        if (!alcMakeContextCurrent(m_context))
        {
            alcDestroyContext(m_context);
            alcCloseDevice(m_device);
            throw std::runtime_error("Failed to make context current");
        }

        alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
	}

	Audio::~Audio() {

		alcMakeContextCurrent(NULL);
		alcDestroyContext(m_context);
		alcCloseDevice(m_device);
	}

}