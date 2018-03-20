#include "InputManager.hpp"

//This boolean will check to see if the item for out buttons are being clicked.
bool InputManager::IsSpriteClicked( sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window )
{
    //Creating a window the size of the sprite of our button.
    //To do this it takes the parameters of the sprites width and height
    if ( sf::Mouse::isButtonPressed( button ))
    {
        sf::IntRect tempRect( object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height );
        
        //if the click is inside the window of the sprite, bool returns true.
        if( tempRect.contains( sf::Mouse::getPosition( window ) ) )
        {
            return true;
        }
    }
    
    //If click is not inside the window of our sprite, bool returns false.
    return false;
}

//Returns the location of the mouse.
sf::Vector2i InputManager::GetMousePosition( sf::RenderWindow &window)
{
    return sf::Mouse::getPosition( window );
}
