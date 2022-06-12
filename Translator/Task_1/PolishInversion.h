#pragma once
#include <string>
#include <list>
#include <vector>

using namespace std;

class PolishInversion
{
public:
	PolishInversion();
	~PolishInversion() {};
	string Translate(string input);
private:

	list<string> _dictionary;
	vector<string> _inputText;
	list<string> _outputText;
	list<string> _memo;
	list<string> _mathInput;
	list<double> _digitBuffer;
	list<string> _operation;
	
	bool _SymbolCheck(string check);
	bool _StringToVector(string input);
	bool _BracketCheck();
	int _RangOperation(string operation);
	bool _Math();
};