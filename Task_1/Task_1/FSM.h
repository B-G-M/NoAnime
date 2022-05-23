#pragma once
#include "Lexer.h"
#include "Hash.h"
#include <string>
#include <vector>

class FSM 
{
public:
	FSM();
	~FSM(){};

	string test();

private:
	Lexer lexer;
	vector<string> _text;
	vector<string> _alphabet;
	vector<int> _finalStates;
	int _currentState;
	string path;
	Hash<int>* _transitions;

	bool _CheckExistTransition(int state, string word);
	bool _CheckWordInAlphabet(string word);
	void _ChangeState(string word);

};

