#include "Sound.h"
#include "stb_vorbis.c"
namespace TurboHybridEngine {

	void Sound::on_load() {

		std::vector<unsigned char> data;

		int channels = 0;
		int sampleRate = 0;
		short* output = NULL;

		size_t samples = stb_vorbis_decode_filename((get_path().c_str()),
			&channels, &sampleRate, &output);

		if (samples == -1)
		{
			throw std::runtime_error("Failed to open file '" + get_path() + "' for decoding");
		}

		// Record the format required by OpenAL
		if (channels < 2)
		{
			m_format = AL_FORMAT_MONO16;
		}
		else
		{
			m_format = AL_FORMAT_STEREO16;
		}

		// Copy (# samples) * (1 or 2 channels) * (16 bits == 2 bytes == short)
		data.resize(samples * channels * sizeof(short));
		memcpy(&data.at(0), output, data.size());

		// Record the sample rate required by OpenAL
		m_frequency = sampleRate;

		// Clean up the read data
		free(output);

		alGenBuffers(1, &m_bufferId);

		alBufferData(m_bufferId, m_format, &data.at(0),
			static_cast<ALsizei>(data.size()), m_frequency);
	}

}