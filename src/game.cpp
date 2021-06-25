#include "game.hpp"
#include "scene.hpp"

namespace Game {
	void play(Scene* first_scene, sf::RenderWindow* window){
		Scene* current_scene = first_scene;
		while (current_scene != nullptr) {
			current_scene = current_scene->play(window);
		}
	}
}