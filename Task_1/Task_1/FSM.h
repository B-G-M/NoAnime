#pragma once
#include "Lexer.h"
#include "Hash.h"
#include <string>
#include <vector>

class FSM 
{
public:
	FSM(Lexer lexer);
	~FSM(){};

	string test();

private:
	vector<string> _text;
	vector<string> _alphabet;
	vector<int> _finalStates;
	int _currenttState;
	
	Hash<int> _transitions;

	bool _CheckExistTransition(int state, string word);
	bool _CheckWordInAlphabet(string word);
	void _ChangeState(string word);

};

