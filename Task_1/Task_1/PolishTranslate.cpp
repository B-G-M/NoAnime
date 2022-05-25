#include <string>
#include <list>
#include <vector>
#include "PolishTranslate.h"

string PolishTranslate::_Translate(string input)
{
	bool ok = _StringToVector(input);
	if (!ok)
	{
		return "Боря душнич!!!";
	}
	_BracketCheck();

	int symbolCount = 0;
	for (int i = 0; i < _inputText.size(); i++)
	{
		if (symbolCount > 1 && _SymbolCheck(_inputText[i]))
		{
			if (_RangOperation(_memo.back(), _inputText[i]) == -1)
				return "Боря душнич!!!!!!!!!!!!!!!!!!!!!!!!!!!";
			else if(_RangOperation(_memo.back(), _inputText[i]) == 0)
			{
				while (_memo.size() != 0)
				{
					_outputText.push_back(_memo.back());
					_memo.pop_back();
				}
			}
		}

		if (!_SymbolCheck(_inputText[i]))
		{
			_outputText.push_back(_inputText[i]);
			symbolCount++;
		}
		else
		{
			_memo.push_back(_inputText[i]);
		}
	}
	if (_memo.size() != 0)
	{
		while (_memo.size() != 0)
		{
			_outputText.push_back(_memo.back());
			_memo.pop_back();
		}
	}
	string ret = "";
	while (_outputText.size() != 0)
	{
		ret += _outputText.front();
		_outputText.pop_front();
	}
		

	return ret;
}

bool PolishTranslate::_StringToVector(string input)
{
	string buffer = "";
	bool statusOK = true;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == ' ')
		{
			_inputText.push_back(buffer);
			buffer = "";
			continue;
		}
		/*if (input[i] == ';')
		{
			if (i < input.size() - 1)
			{
				return false;
			}
			statusOK = true;
		}*/
		buffer += input[i];
	}
	_inputText.push_back(buffer);
	return statusOK;
}

bool PolishTranslate::_BracketCheck()
{
	int bracket = 0;
	for (int i = 0; i < _inputText.size(); i++)
	{
		if (_inputText[i] == "(")
			bracket++;
		else if (_inputText[i] == ")")
			bracket--;
		if (bracket < 0)
			return false;
	}
	if (bracket > 0)
	{
		return false;
	}
	return true;
}

int PolishTranslate::_RangOperation(string operation1, string operation2)
{
	if (operation1 == "+" || operation1 == "-")
	{
		if (operation2 == ")")
			return 2;
		else if (operation2 == "*" || operation2 == "/")
			return 1;
		else if (operation2 == "+" || operation2 == "-")
			return 0;
	}
	else if (operation1 == "*" || operation1 == "/")
	{
		if (operation2 == ")")
			return 2;
		else if (operation2 == "*" || operation2 == "/")
			return 0;
		else if (operation2 == "+" || operation2 == "-")
			return 0;
	}
	else if (operation1 == ")")
	{
		return 3;
	}
	return -1;
}

PolishTranslate::PolishTranslate()
{
	_dictionary.push_back("+");
	_dictionary.push_back("-");

	_dictionary.push_back("/");
	_dictionary.push_back("*");

	_dictionary.push_back("(");
	_dictionary.push_back(")");
}

bool PolishTranslate::_SymbolCheck(string check)
{
	for (auto iter = _dictionary.begin(); iter != _dictionary.end(); iter++)
	{
		if (*iter == check)
			return true;
	}
	return false;
}


//if (symbolCount > 1)
//{
//
//	string nextOper = "";
//
//	if (_SymbolCheck(_inputText[i]))
//		nextOper = _inputText[i];
//	else if (i == _inputText.size() - 2)
//	{
//		nextOper = _memo.back();
//		_outputText.push_back(_inputText[i + 1]);
//	}
//
//
//	if (_RangOperation(_memo.back(), nextOper) == -1)
//		return "Это ерор, а Андрей пидор!!!";
//
//	else if (_RangOperation(_memo.back(), nextOper) == 0)
//	{
//		while (_memo.size() != 0)
//		{
//			_outputText.push_back(_memo.back());
//			_memo.pop_back();
//		}
//		symbolCount = 1;
//	}
//	//else if(_RangOperation(*_memo.end(), nextOper) == 2)
//}
