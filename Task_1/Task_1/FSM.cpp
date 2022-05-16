#include "FSM.h"
#include "Lexer.h"

FSM::FSM(Lexer states, Lexer initialState, Lexer acceptingStates, Lexer nextState)
{
    this->states = states;
    this->initialState = initialState;
    this->acceptingStates = acceptingStates;
    this->nextState = nextState;
}




FSM::~FSM()
{

}
