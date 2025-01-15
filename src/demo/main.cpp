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
		if (get_keyboard()->IsKey(SDLK_w)) {
			get_entity()->get_component<Transform>()->setPosition(get_position() + glm::vec3(0.0f, 0.0f, 0.1f));
		}
		if (get_keyboard()->IsKey(SDLK_s)) {
			get_entity()->get_component<Transform>()->setPosition(get_position() + glm::vec3(0.0f, 0.0f, -0.1f));
		}
		if (get_keyboard()->IsKey(SDLK_a)) {
			get_entity()->get_component<Transform>()->setPosition(get_position() + glm::vec3(-0.1f, 0.0f, 0.0f));
		}
		if (get_keyboard()->IsKey(SDLK_d)) {
			get_entity()->get_component<Transform>()->setPosition(get_position() + glm::vec3(0.1f, 0.0f, 0.0f));
		}
		if (get_mouse()->IsMouseDown(SDL_BUTTON_LEFT)) {
			//get_entity()->get_component<AudioSource>()->Play();
		}
		if (get_mouse()->IsMouseDown(SDL_BUTTON_RIGHT)) {
			get_entity()->get_component<AudioSource>()->Play();
		}
	}

	void on_gui() {

		int buttonDo = get_gui()->Button(glm::vec2(100, 100), glm::vec2(100, 100), get_entity()->get_core()->GetResources()->load<Texture>("../assets/Whiskers_diffuse.png"));
		if (buttonDo == 1) {
			std::cout << "Button pressed" << std::endl;
		}
		else if (buttonDo == 2) {
			std::cout << "Button not pressed" << std::endl;
		}

		int Image = get_gui()->Image(glm::vec2(100, 100), glm::vec2(100, 100), get_entity()->get_core()->GetResources()->load<Texture>("../assets/Whiskers_diffuse.png"));
	}
};



#undef main
int main() {
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Resources> resources = core->GetResources();


	// entity 1
	std::shared_ptr<Entity> entity = core->add_entity();
	std::shared_ptr<Player> p = entity->add_component<Player>();

	std::shared_ptr<AudioSource> audio = entity->add_component<AudioSource>();
	audio->SetSound(core->GetResources()->load<Sound>("../assets/Audio/dixie_horn.ogg"));

	std::shared_ptr<ModelRenderer> r = entity->add_component<ModelRenderer>();
	r->setTexturePath(resources->load<Texture>("../assets/Whiskers_diffuse.png"));
	r->setModelPath(resources->load<Model>("../assets/curuthers.obj"));
	entity->get_component<Transform>()->setPosition(glm::vec3(-2.0f, 0.0f, -10.0f));

	std::shared_ptr<BoxCollider> entityCollider = entity->add_component<BoxCollider>();
	entity->add_component<Rigidbody>();


	// entity 2
	std::shared_ptr<Entity> entity2 = core->add_entity();
	std::shared_ptr<ModelRenderer> r2 = entity2->add_component<ModelRenderer>();

	//r2->setTexturePath(resources->load<Texture>("../assets/F1Tex.png"));
	//r2->setModelPath(resources->load<Model>("../assets/F1Car.obj"));
	r2->setTexturePath(resources->load<Texture>("../assets/Whiskers_diffuse.png"));
	r2->setModelPath(resources->load<Model>("../assets/curuthers.obj"));

	//entity2->get_component<Transform>()->setScale(glm::vec3(0.01f, 0.01f, 0.01f));
	entity2->get_component<Transform>()->setPosition(glm::vec3(2.0f, 0.0f, -10.0f));
	//entity2->get_component<Transform>()->setRotation(glm::vec3(0.0f, 70.0f, 0.0f));

	std::shared_ptr<BoxCollider> entityCollider2 = entity2->add_component<BoxCollider>();

	core->run();

	return 0;
}