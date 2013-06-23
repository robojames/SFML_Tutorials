#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include "Tile.h"
#include "TileMap.h"
#include <sstream>

sf::Texture LoadTexture(std::string file) {

	sf::Texture texture;
	if (!texture.loadFromFile(file)) {
		std::cout << "Error reading from file: " << file << std::endl;
	}

	return texture;
}

sf::Texture LoadTexture(std::string file, sf::IntRect rect) {
	
	sf::Texture texture;

	if (!texture.loadFromFile(file, rect)) {
		std::cout << "Error reading from file: " << file << std::endl;
	}

	return texture;
}



int main(int argc, char** args)
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML Works!");

	sf::RenderWindow* p_window = &window;

	sf::RectangleShape shape(sf::Vector2f(640,1024));

	sf::IntRect rectangle( 0, 0, 30, 30);


	// NOTE:  Default constructor is NOT called if the following notation is utilized:
	//			TileMap mytilemap();
	//			Though I don't know why...
	TileMap mytilemap;
	
	sf::Text text;

	sf::Font font;

	font.loadFromFile("C:/Windows/Fonts/arial.ttf");

	text.setFont(font);

	text.setPosition( 900, 400 );
	text.setCharacterSize(50);

	// END TEST

	shape.setTexture(&mytilemap.TileMap_Textures[0]);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

			if (rectangle.contains(mousePosition.x, mousePosition.y)) {
				std::cout << "You clicked the texture shown!" << std::endl;
			}

		}

		for (unsigned int i = 0; i < mytilemap.TileMap_Sprites.size(); i++) {
			
			std::stringstream Display;
			
			Display << "Showing Tile: " << i;
			
			text.setString(Display.str());
		    window.clear(sf::Color::Black);
			mytilemap.TileMap_Sprites[i].setPosition( 960, 540 );
			sf::sleep(sf::Time(sf::seconds(0.5f)));
			window.draw(mytilemap.TileMap_Sprites[i]);
			window.draw(text);

			window.display();

			

		}

		window.clear(sf::Color::Black);
		window.draw(shape);
		window.display();

	}

	window.~RenderWindow();


	return 0;

}
