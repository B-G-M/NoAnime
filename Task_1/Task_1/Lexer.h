#pragma once
#include <string>
#include <list>
#include "Hash.h"
using namespace std;

class Lexer
{
public:
	Lexer();
	~Lexer();
	
	list<string> FileReader();
	string* GetStates();
	string* GetAlphabet();
	Hash<int> GetTransitions();
	void StringAnalyzer();
private:
	int _statesCount;
	string _text;
	string* _alphabet;
	Hash<int> _transitions;
	int _sizeAlphabet;
	int _sizeFinalStates;
	int* _finalStates;
	int _startState;
	
	
};

