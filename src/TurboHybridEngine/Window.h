#include <SDL2/SDL.h>

namespace TurboHybridEngine {

	struct Core;

	struct Window {

		Window();
		~Window();

	private:
		friend struct TurboHybridEngine::Core;

		SDL_Window* m_raw;
		SDL_GLContext m_context;
	};
}