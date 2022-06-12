#pragma once
#include "Lexer.h"
#include "Hash.h"
#include <string>
#include <vector>

class FSM 
{
public:
	FSM(string fileName);
	~FSM(){};

	string test(string text);

private:
	Lexer lexer;
	string _text;
	//vector<string> _vars;
	vector<string> _alphabet;
	vector<int> _finalStates;
	int _currentState;
	string path;
	Hash<int>* _transitions;

	bool _isSymbol(char symbol1,string symbol2);
	bool _CheckExistTransition(int state, string word);
	bool _CheckWordInAlphabet(string word);
	bool _ChangeState(string word);

};

