#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main()
{
    //Creating the game window, 860x540 pixels with title "The Floor Is Lava"
    sf::RenderWindow window( sf::VideoMode( 860, 540 ), "The Floor Is Lava");
    
    //Creating the background image sprite and the texture file(background image) to cover the sprite.
    //If there is an error loading the image, and error message shows in the IDE command prompt.
    sf::Texture menuBackground;
    sf::Sprite menuBackgroundImage;
    //production file location: "../Resources/Images/VolcanoBG.png"
    if ( !menuBackground.loadFromFile("/Users/chipbrommer/Desktop/OOP-Game/Resources/Images/VolcanoBG.png") )
    {
        std::cout << "Error: Can't load background image." << std::endl;
    }
    
    //Setting the background image to the texture previously created.
    menuBackgroundImage.setTexture(menuBackground);
    
    //Creating the font "gameFontBold" which will be the bold version of the font used through out the game for all
    //strings. If there is an error loading the font, and error message shows in the IDE command prompt.
    sf::Font gameFontBold;
    //production file location: "../Resources/Font/WalkwayBold.ttf"
    if (!gameFontBold.loadFromFile("/Users/chipbrommer/Desktop/OOP-Game/Resources/Font/WalkwayBold.ttf"))
    {
        std::cout << "Error: Can't load bold font file." << std::endl;
    }
    
    sf::Font gameFont;
    //production file location: "../Resources/Font/Walkway.ttf"
    if (!gameFont.loadFromFile("/Users/chipbrommer/Desktop/OOP-Game/Resources/Font/Walkway.ttf"))
    {
        std::cout << "Error: Can't load font file." << std::endl;
    }
    
    
    //Creating the header for the main menu, in brackets are all of its attributes.
    sf::Text menuHeader;
    {
        menuHeader.setFont( gameFontBold );
        menuHeader.setString("The Floor Is Lava!");
        menuHeader.setFillColor(sf::Color::White);
        menuHeader.setStyle( sf::Text::Bold );
        menuHeader.setCharacterSize(50);
        menuHeader.setPosition(165.0f, 140.0f);
    }
    
    //Creating the credit for the bottom, contains team name
    sf::Text menuCredit;
    {
        menuCredit.setFont( gameFont );
        menuCredit.setString("By Team: OOP I DID IT AGAIN");
        menuCredit.setFillColor(sf::Color::Red);
        menuCredit.setStyle( sf::Text::Bold );
        menuCredit.setCharacterSize(16);
        menuCredit.setPosition(270.0f, 500.0f);
    }
    
    //While loop for the game.
    while ( window.isOpen( ) )
    {
        sf::Event Event;
        
        // Handle all events
        while (window.pollEvent(Event))
        {
               //If user clicks the exit on top or with the tool bar, window closes.
               if(Event.type == sf::Event::Closed)
               {
                    window.close();
               }
            
            if(Event.type == sf::Event::KeyPressed)
               {
                   if(Event.key.code == sf::Keyboard::Return)
                   {
                       //When user presses enter, game will auto start,
                       //Start game code goes here.
                       //Will call the game window
                   }
                   
                   //If the user presses the escape key, the game will close.
                   if(Event.key.code == sf::Keyboard::Escape)
                   {
                       //Future: pause game (code here)
                       //        pop up message "verifying escape button. press 'esc' again to close.
                       //                        press enter to continue playing."
                       //        use an if/else loop to handle this.
                       window.close();
                   }
               }
        }
        
        //Clears the window on creation
        window.clear();
        
        //Drawing all sprites and strings to the window.
        //Wrapped in brackets for cleanliness.
        {
            window.draw(menuBackgroundImage);
            window.draw(menuHeader);
            window.draw(menuCredit);
        }
        
        //Displays the window to the screen.
        window.display();
    }
}
