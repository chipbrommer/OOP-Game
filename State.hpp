#pragma once

class State
{
    public:
        virtual void Init( ) = 0;
        
        virtual void handleInput( ) = 0;
        virtual void Update( float dt ) = 0;
        
        //Recieves delta time. Allows the game to create the frame independant game play from the
        //machines frame rate.
        virtual void Draw( float dt ) = 0;
        
        virtual void Pause( ) { }
        virtual void Resume( ) { }
        
};

