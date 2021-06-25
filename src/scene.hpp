#pragma once
#include "game.hpp"

class Scene {
public:
	virtual Scene* play(sf::RenderWindow* window) = 0;	
};


class TestScene2 : public Scene {
public:	
	Scene* play(sf::RenderWindow* window) override {
		sf::CircleShape shape(200.f);
		shape.setFillColor(sf::Color::Yellow);

		while (window->isOpen()) {
			sf::Event event;
			while (window->pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window->close();
					return nullptr;
				}
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)){
				return nullptr;
			}
			window->clear();
			window->draw(shape);
			window->display();
		}
		return nullptr;
	}
};

class TestScene : public Scene {
public:	
	Scene* play(sf::RenderWindow* window) override {
		sf::CircleShape shape(200.f);
		shape.setFillColor(sf::Color::Green);

		while (window->isOpen()) {
			sf::Event event;
			while (window->pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window->close();
					TestScene2* scene = new TestScene2;
					return scene;
				}
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
				TestScene2* scene = new TestScene2;
				return scene;
			}
			window->clear();
			window->draw(shape);
			window->display();
		}
		TestScene2* scene = new TestScene2;
		return scene;
	}
};
