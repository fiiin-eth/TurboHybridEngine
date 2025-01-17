#include "Rigidbody.h"

#include "Entity.h"
#include "Core.h"
#include "Component.h"
#include "Transform.h"
#include "BoxCollider.h"
#include <vector>
#include <iostream>

namespace TurboHybridEngine
{
	void Rigidbody::on_tick()
	{
		std::vector<std::shared_ptr<BoxCollider>> boxColliders;
		get_entity()->get_core()->Find(boxColliders);

		for (auto boxCollider : boxColliders) {
			if (boxCollider->get_transform() == get_transform()) {
				continue;
				
			}
			if (boxCollider->IsColliding(get_entity()->get_component<BoxCollider>())) {
				/*std::cout << "IsColliding" << std::endl;*/

				for (size_t ci = 0; ci < get_entity()->m_components.size(); ci++) {
					get_entity()->m_components.at(ci)->on_collision();
				}
				for (size_t ci = 0; ci < boxCollider->get_entity()->m_components.size(); ci++) {
					boxCollider->get_entity()->m_components.at(ci)->on_collision();
				}
			}
		}
	}
}