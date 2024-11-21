#include <TurboHybridEngine/TurboHybridEngine.h>

using namespace TurboHybridEngine;

struct Player : Component {

	void on_initialize() {
		printf("initialized\n");
	}
private:
	int m_dummy;

	void on_tick() {
		printf("tick\n");
	}


};

#undef main
int main() {
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> entity = core->add_entity();

	std::shared_ptr<Player> p = entity->add_component<Player>();

	//entity->add_component<TriangleRenderer>();

	std::shared_ptr<Entity> entity = core->add_entity();

	//Resources resources;
	//std::shared_ptr<Texture> Tex = resources.load<Texture>("../assets/Whiskers_diffuse.png");
	//std::shared_ptr<Model> Mod = resources.load<Model>("../assets/Whiskers.obj");

	std::shared_ptr<TriangleRenderer> r = entity->add_component<TriangleRenderer>();

	std::shared_ptr<Resources> resources = core->GetResources();
	std::shared_ptr<Texture> Tex = resources->load<Texture>("../assets/Whiskers_diffuse.png");
	std::shared_ptr<Model> Mod = resources->load<Model>("../assets/curuthers.obj");
	r->setTexturePath(Tex->GetTexture());
	r->setModelPath(Mod->GetModel());

	core->run();

	return 0;
}