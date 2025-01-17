#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "Window.h"
#include "Resources.h"
#include "Input.h"
#include "Audio.h"
#include "GUI.h"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <iostream>


namespace TurboHybridEngine {

	std::shared_ptr<Core> Core::initialize() {

		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->m_window = std::make_shared<Window>();
		rtn->m_resources = std::make_shared<Resources>();
		rtn->m_input = std::make_shared<Input>();
		rtn->m_audio = std::make_shared<Audio>();
		rtn->m_gui = std::make_shared<GUI>(rtn);
		rtn->m_self = rtn;

		return rtn;

	}


	std::shared_ptr<Entity> Core::add_entity() {

		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

		rtn->m_core = m_self;
		rtn->m_self = rtn;
		std::cout << rtn->m_core.lock().get() << std::endl;

		rtn->add_component<Transform>();

		m_entities.push_back(rtn);

		return rtn;

	}

	void Core::run() {

		bool running = true;

		while (running)
		{
			for (size_t ei = 0; ei < m_entities.size(); ++ei) {
				m_entities.at(ei)->tick();
			}

			m_input->Update();

			glClearColor(0, 0.5f, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			for (size_t ei = 0; ei < m_entities.size(); ++ei) {
				m_entities.at(ei)->render();
			}

			for (size_t ei = 0; ei < m_entities.size(); ++ei) {
				m_entities.at(ei)->on_gui();
			}

			SDL_GL_SwapWindow(m_window->m_raw);
		}
	}

	std::shared_ptr<Window> Core::window() const {
		return m_window;
	}

	std::shared_ptr<Resources> Core::GetResources() {
		return m_resources;
	}

	std::shared_ptr<Input> Core::get_input() {
		return m_input;
	}

	std::shared_ptr<GUI> Core::gui() {
		return m_gui;
	}
}