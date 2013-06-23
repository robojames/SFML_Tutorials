#include "Tile.h"

// Constructor
Tile::Tile(sf::Vector2<float> Tile_Position)
{
	this->Tile_Position = Tile_Position;
	Tile_Sprite.setPosition(Tile_Position);
}


Tile::~Tile(void)
{
}
