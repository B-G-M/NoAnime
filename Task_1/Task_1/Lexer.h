#pragma once
#include <string>
#include <list>
#include<vector>
#include "Hash.h"
using namespace std;

class Lexer
{
public:
	Lexer();
	~Lexer() {};
	
	void FileReader();
	int GetStatesCount();
	int GetStartState();
	vector<string> GetText();
	vector<string> GetAlphabet();
	vector<int> GetFinalStates();
	Hash<int>* GetTransitions();
	void StringAnalyzer();
private:
	list<string> text;
	int _statesCount = 0;
	int _startState = 0;
	vector<string> _text;
	vector<string> _alphabet;
	vector<int> _finalStates;
	Hash<int> _transitions;
	
	
	
};

