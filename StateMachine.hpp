#pragma once

#include <memory>
#include <stack>

#include "State.hpp"

typedef std::unique_ptr<State> StateRef;
    
class StateMachine
{
    public:
        //Default Constructor
        StateMachine() {}
        
        //De-Constructor
        ~StateMachine() {}
        
        //Allows us to switch screens from menu -> game -> end or credits, wtc.
        //is Replacing = true because by default we want to replace the screen
        //and not just overlap.
        void AddState( StateRef newState, bool isReplacing = true);
        
        //To manually remove a state if necessary
        void RemoveState();
        
        //Runs at the stast of each game cpp file. What impliments the change of screen.
        void ProcessStateChanges();
    
        //Will return the top state from the stack and that is the state that gets run.
        StateRef &GetActiveState( );
        
    private:
        //All of our states that are currently on the stack. Holds a pointer to our states.
        std::stack<StateRef> _states;
        StateRef _newState;
        
        //Bool for removing a state
        bool _isRemoving;
        
        //Bool for adding a state
        bool _isAdding;
        
        //Bool for replacing a state
        bool _isReplacing;
};
