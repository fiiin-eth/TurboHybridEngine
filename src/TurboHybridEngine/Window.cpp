#include "Window.h"
#include <stdexcept>
#include <GL/glew.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

namespace TurboHybridEngine {
	Window::Window() {

		m_raw = SDL_CreateWindow("Triangle",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			WINDOW_WIDTH, WINDOW_HEIGHT,
			SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		if (!m_raw)
		{
			throw std::exception();
		}

		m_context = SDL_GL_CreateContext(m_raw);

		if (!m_context)
		{
			throw std::exception();
		}

		if (glewInit() != GLEW_OK)
		{
			throw std::exception();
		}

		
	}

	Window::~Window() {

		SDL_GL_DeleteContext(m_context);
		SDL_DestroyWindow(m_raw);
		SDL_Quit();

	}

}