#pragma once
#include "Lexer.h"

class FSM 
{
public:
	

	FSM(Lexer states, Lexer initialState, Lexer acceptingStates, Lexer nextState);

	Lexer states;
	Lexer initialState;
	Lexer acceptingStates;
	Lexer nextState;

	~FSM();


private:
	 
};

