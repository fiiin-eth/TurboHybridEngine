#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

namespace TurboHybridEngine {

	std::shared_ptr<Core> Core::initialize() {

		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->m_self = rtn;

		SDL_Window* window = SDL_CreateWindow("Triangle",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			WINDOW_WIDTH, WINDOW_HEIGHT,
			SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		if (!SDL_GL_CreateContext(window))
		{
			throw std::exception();
		}

		if (glewInit() != GLEW_OK)
		{
			throw std::exception();
		}


		return rtn;

	}


	std::shared_ptr<Entity> Core::add_entity() {

		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

		rtn->m_core = m_self;
		std::cout << rtn->m_core.lock().get() << std::endl;

		rtn->add_component<Transform>();

		m_entities.push_back(rtn);

		return rtn;

	}

	void Core::run() {
		for (size_t i = 0; i < 25; ++i) {
			for (size_t ei = 0; ei < m_entities.size(); ++ei) {
				m_entities.at(ei)->tick();
			}
		}
	}
}