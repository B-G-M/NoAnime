#pragma once
#include "Lexer.h"
#include "Hash.h"
#include <string>
class FSM 
{
public:
	FSM(Lexer lexer);
	~FSM();

	string test();

private:
	Hash<string> _states;
	string _currenttState;
	string* _finalStates;
	string** _transitions;

	bool _CheckExistTransition(string state, string word);
	void _ChangeState(string word);

};

