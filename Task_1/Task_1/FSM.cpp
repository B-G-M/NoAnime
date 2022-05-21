#include "FSM.h"
#include "Lexer.h"

FSM::FSM(Lexer lexer)
{
	this->_states = ;
	this->_currenttState = startState;
	this->_finalStates = finalStates;
	this->_transitions = transitions;
}




FSM::~FSM()
{

}

bool FSM::_CheckExistTransition(string state, string word)
{
	for (size_t i = 0; i < _transitions; i++)
	{

	}

	return(this->_transitions[state] && this->_transitions[state][word]);
}

void FSM::_ChangeState(string word)
{
	if (this->_CheckExistTransition(this->_currenttState, word))
	{
		this->_currenttState = this->_transitions[this->_currenttState][word];
	}
	else
	{
		throw exception("Ќе существует перехода из текущего состо€ни€");
	}
}
