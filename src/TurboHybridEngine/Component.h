#ifndef TurboHybridEngine_COMPONENT_H
#define TurboHybridEngine_COMPONENT_H


namespace TurboHybridEngine {

	struct Component {
		virtual void on_initialize();
		virtual void on_tick();
		virtual void on_render();
	private:
		friend struct Entity;
		void tick();
		void render();
	};

}

#endif