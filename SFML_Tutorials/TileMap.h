#pragma once
#include<vector>
#include <SFML\Graphics.hpp>
#include "Tile.h"
#include <iostream>
#include <string>
#include <fstream>

/// <summary>
/// TileMap for the Farming Game Engine
/// </summary>
class TileMap
{
public:
	/// <summary>
	/// The tiles
	/// </summary>
	std::vector< std::vector < Tile > > Tiles;

    /// <summary>
	/// The tile map_ sprites
	/// </summary>
	std::vector< sf::Sprite > TileMap_Sprites;

	/// <summary>
	/// The tile map_ textures
	/// </summary>
	std::vector< sf::Texture > TileMap_Textures;

	TileMap(void);

	~TileMap(void);

	void LoadTextures(void);
	
	void GenerateSpriteArray();
	
	void RenderMap(sf::RenderWindow*);
private:
	/// <summary>
	/// The file_ names
	/// </summary>
	std::vector< std::string > File_Names;
	
	/// <summary>
	/// The source rectangles used for clipping raw sprite sheets
	/// </summary>
	std::vector< sf::IntRect > Source_Rectangles;

	/// <summary>
	/// The tile width
	/// </summary>
	const static int TileWidth = 64;

	/// <summary>
	/// The tile height
	/// </summary>
	const static int TileHeight = 64;
};

