#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "Window.h"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>


namespace TurboHybridEngine {

	std::shared_ptr<Core> Core::initialize() {

		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->m_window = std::make_shared<Window>();
		rtn->m_self = rtn;



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

		bool running = true;

		while (running)
		{
			SDL_Event event = { 0 };

			while (SDL_PollEvent(&event)) {

				if (event.type == SDL_QUIT) {

					running = false;
				}
				else if (event.type == SDL_KEYDOWN){
					std::cout << ("event");
				}
			}


			for (size_t ei = 0; ei < m_entities.size(); ++ei) {
				m_entities.at(ei)->tick();
			}

			//SDL_GL_ClearWindow(m_window->m_raw);
			glClearColor(1, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			for (size_t ei = 0; ei < m_entities.size(); ++ei) {
				//m_entities.at(ei)->render();
			}

			SDL_GL_SwapWindow(m_window->m_raw);
		}
	}

	std::shared_ptr<Window> Core::window() const {
		return m_window;
	}
}