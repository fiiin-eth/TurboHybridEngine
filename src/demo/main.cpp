#include <TurboHybridEngine/TurboHybridEngine.h>
#include <memory>

using namespace TurboHybridEngine;

struct Player : Component {

	Player() : m_dummy(0) {
		printf("Player created\n");
	}

	void on_initialize() {
		printf("initialized\n");
	}
private:
	int m_dummy;

	void on_tick() {
		//printf("tick\n");
		if (get_keyboard()->IsKeyDown(119)) {
			printf("hello\n");
			
		}
	}


};

#undef main
int main() {
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> entity = core->add_entity();

	std::shared_ptr<Player> p = entity->add_component<Player>();

	std::shared_ptr<Resources> resources = core->GetResources();

	std::shared_ptr<TriangleRenderer> r = entity->add_component<TriangleRenderer>();
	r->setTexturePath(resources->load<Texture>("../assets/Whiskers_diffuse.png"));
	r->setModelPath(resources->load<Model>("../assets/curuthers.obj"));
	entity->get_component<Transform>()->setPosition(glm::vec3(-2.0f, 0.0f, -10.0f));


	//std::shared_ptr<Entity> entity2 = core->add_entity();
	//std::shared_ptr<TriangleRenderer> r2 = entity2->add_component<TriangleRenderer>();
	//std::shared_ptr<Texture> Tex2 = resources->load<Texture>("../assets/F1Tex.png");
	//std::shared_ptr<Model> Mod2 = resources->load<Model>("../assets/F1Car.obj");
	//r2->setTexturePath(Tex2->GetTexture());
	//r2->setModelPath(Mod2->GetModel());
	//entity2->get_component<Transform>()->setScale(glm::vec3(0.01f, 0.01f, 0.01f));
	//entity2->get_component<Transform>()->setPosition(glm::vec3(2.0f, -3.0f, -10.0f));
	//entity2->get_component<Transform>()->setRotation(glm::vec3(0.0f, 70.0f, 0.0f));


	core->run();

	return 0;
}