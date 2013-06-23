#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Tile
{
public:
	sf::Sprite Tile_Sprite;
	sf::Vector2<float> Tile_Position;
	Tile(sf::Vector2<float> Position);
	~Tile(void);
private:

};

