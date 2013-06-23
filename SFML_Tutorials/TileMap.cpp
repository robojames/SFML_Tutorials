#include "TileMap.h"

/// <summary>
/// Initializes a new instance of the <see cref="TileMap"/> class.
/// </summary>
TileMap::TileMap()
{
	LoadTextures();
	GenerateSpriteArray();
}


TileMap::~TileMap(void)
{
	// Clears all std::vector's used to disallow further use
	this->File_Names.clear();
	this->Source_Rectangles.clear();
	this->TileMap_Sprites.clear();
	this->TileMap_Textures.clear();
}


/// <summary>
/// Loads the raw images used in the Farming game engine, then cutes them into appropriate
/// sprites by using a clipping rectangle based on the sprite sheet.
/// </summary>
void TileMap::LoadTextures(void) {
	
	
	// Add the names of the texture files (should automate this in the future) to the vector
	File_Names.push_back("../tilesheet1.png");
	
	sf::Texture Texture_Sheet_1;

	// Loads texture from raw image into memory for chopping via Sprites
	if (!Texture_Sheet_1.loadFromFile(File_Names[0]))
	{
		std::cout << "Error reading from: " << File_Names[0] << std::endl;
	}
	else
	{
		std::cout << "Texture read succesfully into memory." << std::endl;
	}

	TileMap_Textures.push_back(Texture_Sheet_1);

	

	// Number of sprites on the sprite sheet in both the X and Y directions
	int n_Sprites_X_1 = 10;
	int n_Sprites_Y_1 = 14;
		
	// Generate rectangles (based on the sprite sheet) to use to trim the textures accordingly
	for (int j = 0; j <= n_Sprites_Y_1; j++)
	{
		for (int i = 0; i <= n_Sprites_X_1 ; i++)
		{
			Source_Rectangles.push_back(sf::IntRect((i * TileWidth), (j * TileHeight), TileWidth, TileHeight));
		}

	}

	// Loop through each tile again to check for errors if debugging
#if _DEBUG
	for (unsigned int i = 0; i < Source_Rectangles.size(); i++) {
		std::cout << "Tile: " << i << ", rectangle has position ( " << Source_Rectangles[i].left << ", " << Source_Rectangles[i].top << " )" << std::endl;
	}

	std::cout << "Reading sprite sheet 1... success." << std::endl;
#endif


#if _DEBUG
	std::cout << "TileMap_Sprites size:  " << TileMap_Sprites.size() << std::endl;
#endif

}

/// <summary>
/// Generates the sprite array, and sets initial properties
/// </summary>
void TileMap::GenerateSpriteArray() {
		
	// Generates and fills the Sprites for the TileMap_Sprites
	for (unsigned int i = 0; i < Source_Rectangles.size(); i++)
	{
		sf::Sprite Temp;

		Temp.setTexture(TileMap_Textures[0]);
		
		Temp.setTextureRect(Source_Rectangles[i]);

		Temp.setScale(3.0,3.0);

		TileMap_Sprites.push_back(Temp);

#if _DEBUG
		std::cout << "Generated texture:  " << i << std::endl;
#endif

	}

}

/// <summary>
/// Renders the map.
/// </summary>
/// <param name="window">The render window.</param>
void TileMap::RenderMap(sf::RenderWindow *window)
{
	
}
