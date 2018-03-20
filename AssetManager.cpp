#include "AssetManager.hpp"


//This function loads the textures for the game.
void AssetManager::LoadTexture( std::string name, std::string fileName )
{
    sf::Texture texture;
        
    //When the file loads successfullys, it gets added to the map of textures that we
    //have already created.
    if (texture.loadFromFile( fileName ) )
    {
        this->_textures[name] = texture;
    }
}

sf::Texture &AssetManager::GetTexture(std::string name)
{
    return this->_textures.at( name );
}

//This function loads the fonts for the game.
void AssetManager::LoadFont( std::string name, std::string fileName )
{
    sf::Font font;
    
    //When the file loads successfullys, it gets added to the map of fonts that we
    //have already created.
    if (font.loadFromFile( fileName ) )
    {
        this->_fonts[name] = font;
    }
}

sf::Font &AssetManager::GetFont(std::string name)
{
    return this->_fonts.at( name );
}

