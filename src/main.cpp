#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "scene.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "aiballs");

    TestScene test_scene;

    Game::play(&test_scene, &window);
    
}