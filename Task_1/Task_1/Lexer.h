#pragma once
#include <string>
#include "Queue.h"
using namespace std;

class Lexer
{
public:
	Lexer();
	~Lexer();
	
	string GetText();
	string* GetStates();
	string* GetAlphbet();
	string** GetTransitions();
private:
	string* _states;
	string* _alphabet;
	string** _transitions;
	
};

