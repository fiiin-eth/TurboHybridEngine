#ifndef RESOURCES_H
#define RESOURCES_H

#include <iostream>
#include <vector>
#include <memory>


namespace TurboHybridEngine {


	struct Resource;
	struct Resources {

		template <typename T>
		std::shared_ptr<T> load(const std::string& _path) {

			for (size_t i = 0; i < m_resources.size(); ++i) {
				if (m_resources.at(i)->get_path() == _path) {
					//return m_resources.at(i);
					return std::dynamic_pointer_cast<T>(m_resources.at(i));
				}
			}
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->set_path(_path);
			rtn->on_load();
			m_resources.push_back(rtn);

			return rtn;

		}
	private:
		std::vector<std::shared_ptr<Resource>> m_resources;

	};

}

#endif