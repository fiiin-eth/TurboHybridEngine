#include <TurboHybridEngine/TurboHybridEngine.h>
#include <memory>

using namespace TurboHybridEngine;

struct Player : Component {

	Player(){
		printf("Player created\n");
	}

	void on_initialize() {
		printf("initialized\n");
	}
private:
	bool collided = false;
	void on_tick() {
		if (get_keyboard()->IsKey(SDLK_w)) {
			get_entity()->get_component<Transform>()->setPosition(get_position() + glm::vec3(0.0f, 0.0f, 0.03f));
		}
		if (get_keyboard()->IsKey(SDLK_s)) {
			get_entity()->get_component<Transform>()->setPosition(get_position() + glm::vec3(0.0f, 0.0f, -0.03f));
		}
		if (get_keyboard()->IsKey(SDLK_a)) {
			get_entity()->get_component<Transform>()->setPosition(get_position() + glm::vec3(-0.03f, 0.0f, 0.0f));
		}
		if (get_keyboard()->IsKey(SDLK_d)) {
			get_entity()->get_component<Transform>()->setPosition(get_position() + glm::vec3(0.03f, 0.0f, 0.0f));
		}
		if (get_keyboard()->IsKey(SDLK_p)) {
			std::shared_ptr<Entity> Duck = get_entity()->get_core()->add_entity();
			std::shared_ptr<ModelRenderer> DuckRender = Duck->add_component<ModelRenderer>();
			DuckRender->setTexturePath(get_entity()->get_core()->GetResources()->load<Texture>("../assets/DUCKTEX.png"));
			DuckRender->setModelPath(get_entity()->get_core()->GetResources()->load<Model>("../assets/DUCK.obj"));
			Duck->get_component<Transform>()->setPosition(glm::vec3(1.0f, -1.0f, -4.0f));
			Duck->get_component<Transform>()->setScale(glm::vec3(0.02f, 0.02f, 0.02f));
			Duck->get_component<Transform>()->setRotation(glm::vec3(-90.0f, 0.0f, 0.0f));
			std::shared_ptr<BoxCollider> entityCollider2 = Duck->add_component<BoxCollider>();
			entityCollider2->SetSize(vec3(0.02f, 0.02f, 0.02f));
		}
		if (get_mouse()->IsMouseDown(SDL_BUTTON_LEFT)) {

		}
		if (get_mouse()->IsMouseDown(SDL_BUTTON_RIGHT)) {

		}
	}

	void on_collision() {
		collided = true;
	}

	void on_gui() {
		if (collided) {
			get_gui()->Image(glm::vec2(550, 100), glm::vec2(100, 100), get_entity()->get_core()->GetResources()->load<Texture>("../assets/AggyDuck.png"));
		}

		int buttonDo = get_gui()->Button(glm::vec2(100, 100), glm::vec2(100, 100), get_entity()->get_core()->GetResources()->load<Texture>("../assets/Sound.png"));
		if (buttonDo == 1) {
			std::cout << "Button pressed" << std::endl;
			get_entity()->get_component<AudioSource>()->Play();
		}
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
	audio->SetSound(core->GetResources()->load<Sound>("../assets/Audio/CatPur.ogg"));

	std::shared_ptr<ModelRenderer> r = entity->add_component<ModelRenderer>();
	r->setTexturePath(resources->load<Texture>("../assets/Whiskers_diffuse.png"));
	r->setModelPath(resources->load<Model>("../assets/curuthers.obj"));
	entity->get_component<Transform>()->setPosition(glm::vec3(0.0f, -0.5f, -2.0f));
	entity->get_component<Transform>()->setScale(glm::vec3(0.05f, 0.05f, 0.05f));
	std::shared_ptr<BoxCollider> entityCollider = entity->add_component<BoxCollider>();
	entity->add_component<Rigidbody>();


	// entity road
	std::shared_ptr<Entity> entityRoad = core->add_entity();
	std::shared_ptr<ModelRenderer> rRoad = entityRoad->add_component<ModelRenderer>();
	rRoad->setTexturePath(resources->load<Texture>("../assets/Road.png"));
	rRoad->setModelPath(resources->load<Model>("../assets/Road.obj"));
	entityRoad->get_component<Transform>()->setPosition(glm::vec3(-0.56f, -3.0f, -20.0f));
	entityRoad->get_component<Transform>()->setRotation(glm::vec3(0.0f, -90.0f, 0.0f));
	 

	core->run();

	return 0;
}