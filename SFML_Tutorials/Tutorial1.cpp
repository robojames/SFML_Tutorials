//#include <SFML\Graphics.hpp>
//#include <string>
//#include <iostream>
//
//int main(int argc, char** args)
//{
//
//	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML Works!");
//
//	sf::CircleShape shape(400);
//	
//	shape.setFillColor(sf::Color::Blue);
//
//	std::cout << "Testing..." << std::endl;
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed) {
//				window.close();
//			}
//
//			if (event.type == sf::Event::TextEntered) {
//				std::cout << "Character typed:  " << static_cast<char>(event.text.unicode) << std::endl;
//			}
//		}
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//			shape.move(-1, 0);
//		}
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//			shape.move(1,0);
//		}
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//			shape.move(0,-1);
//		}
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
//			shape.move(0,1);
//		}
//
//		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//			shape.setFillColor(sf::Color::Blue);
//		}
//
//		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
//			shape.setFillColor(sf::Color::Green);
//		}
//
//
//
//
//
//		window.clear();
//		window.draw(shape);
//		window.display();
//
//	}
//
//	window.~RenderWindow();
//
//
//	return 0;
//
//}
