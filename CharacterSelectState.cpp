#include <sstream>
#include "Definitions.hpp"
#include "CharacterSelectState.hpp"
#include "MainMenuState.hpp"


#include <iostream>

CharacterSelectState::CharacterSelectState(GameDataRef data) : _data(data)
{
    
}

void CharacterSelectState::Init()
{
    this->_data->assets.LoadTexture("Character Select Background", MAIN_MENU_BACKGROUND);
    this->_data->assets.LoadTexture("Character Select Logo", CHAR_SELECT_LOGO);
    this->_data->assets.LoadTexture("Back Button", BACK_BUTTON);
    
    _background.setTexture(this->_data->assets.GetTexture("Character Select Background"));
    _logo.setTexture(this->_data->assets.GetTexture("Character Select Logo"));
    _backButton.setTexture(this->_data->assets.GetTexture("Back Button"));
    
    _logo.setPosition((SCREEN_WIDTH / 2) - (_logo.getGlobalBounds().width / 2), _logo.getGlobalBounds().height / 2 - 110);
    
    _backButton.setPosition((SCREEN_WIDTH / 2 - 420), SCREEN_HEIGHT / 2 + 218);
}

void CharacterSelectState::HandleInput()
{
    sf::Event event;
    
    while (this->_data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            this->_data->window.close();
        }
        
        if (this->_data->input.IsSpriteClicked(this->_backButton, sf::Mouse::Left, this->_data->window))
        {
            this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
        }
    }
}

void CharacterSelectState::Update(float dt)
{
    
}

void CharacterSelectState::Draw(float dt)
{
    this->_data->window.clear(sf::Color::Red);
    
    this->_data->window.draw(this->_background);
    this->_data->window.draw(this->_logo);
    this->_data->window.draw(this->_backButton);
    
    this->_data->window.display();
}


