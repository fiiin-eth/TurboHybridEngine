#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>

namespace TurboHybridEngine {

	struct Resources;
	struct Resource {

		std::string get_path() const;
		void set_path(const std::string& _path) { m_path = _path; }
		
		virtual void on_load() = 0;

	private:
		friend struct TurboHybridEngine::Resources;

		std::string m_path;

		void load();
	};
}

#endif