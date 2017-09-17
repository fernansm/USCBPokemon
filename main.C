#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(1200, 1200), "SFML works!");
	sf::Texture texture;
	sf::Sprite sprite;

	if (!texture.loadFromFile("character.png")) {
		std::cout << "Error loading image..." << std::endl;
		window.close();
		return 0;
	}

	sprite.setTexture(texture);
	int x = 0;
	int y = 0;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
		}

		sprite.setTextureRect(sf::IntRect(x,y,204,204));

		window.clear();
		window.draw(sprite);
		window.display();

		sf::sleep(sf::milliseconds(100));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			sprite.move(sf::Vector2f(-10,0));
			y = 204;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			sprite.move(sf::Vector2f(10,0));
			y = 0;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			sprite.move(sf::Vector2f(0,-10));
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			sprite.move(sf::Vector2f(0,10));
		}

		x = (x + 204) % 612;
	}

	return 0;
}

