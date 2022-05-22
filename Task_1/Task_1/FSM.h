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
	//int* _states;
	int _sizeAlphabet;
	int _sizeFinalStates;
	string* _alphabet;
	int* _finalStates;
	int _currenttState;
	
	Hash<int> _transitions;

	bool _CheckExistTransition(int state, string word);
	void _ChangeState(string word);

};

