#include <string>
#include <list>
#include <vector>
#include "PolishInversion.h"


string PolishInversion::_Translate(string input)
{
	bool ok = _StringToVector(input);
	if (!ok)
	{
		return "Боря душнич!!!";
	}
	ok = _BracketCheck();
	if (!ok)
	{
		return "Боря душнич!!!";
	}

	bool flag = false;

	int symbolCount = 0;
	for (int i = 0; i < _inputText.size(); i++)
	{
		if (!_SymbolCheck(_inputText[i]))
			_outputText.push_back(_inputText[i]);
		else
		{
			if (_inputText[i] == "(")
			{
				_memo.push_back(_inputText[i]);
			}
			else if(_inputText[i] == ")")
			{
				while (_memo.size()!=0 && _memo.back() != "(")
				{
					_outputText.push_back(_memo.back());
					_memo.pop_back();
				}
				//_memo.pop_back();
			}
			else
			{
				while (_memo.size() != 0 && (_RangOperation(_memo.back()) >= _RangOperation(_inputText[i])))
				{
					_outputText.push_back(_memo.back());
					_memo.pop_back();
				}
				_memo.push_back(_inputText[i]);
			}
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
		if (_outputText.front() == "(" || _outputText.front() == ")")
		{
			_outputText.pop_front();
		}
		else
		{
			ret += _outputText.front();
			_outputText.pop_front();
		}
	}
		

	return ret;
}

bool PolishInversion::_StringToVector(string input)
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
		buffer += input[i];
	}
	_inputText.push_back(buffer);
	return statusOK;
}

bool PolishInversion::_BracketCheck()
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

int PolishInversion::_RangOperation(string operation)
{
	if (operation == "+" || operation == "-")
		return 1;
	else if (operation == "*" || operation == "/")
		return 2;
	else if (operation == ")")
		return 3;
	else if (operation == "(")
		return 0;
	
}

PolishInversion::PolishInversion()
{
	_dictionary.push_back("+");
	_dictionary.push_back("-");

	_dictionary.push_back("/");
	_dictionary.push_back("*");

	_dictionary.push_back("(");
	_dictionary.push_back(")");
}

bool PolishInversion::_SymbolCheck(string check)
{
	for (auto iter = _dictionary.begin(); iter != _dictionary.end(); iter++)
	{
		if (*iter == check)
			return true;
	}
	return false;
}

//if (!_SymbolCheck(_inputText[i]))
//{
//	_outputText.push_back(_inputText[i]);
//}
//else
//{
//	if (_RangOperation(_inputText[i]) != 3)
//	{
//		while (_memo.size() != 0)
//		{
//			if (_RangOperation(_memo.back()) >= _RangOperation(_inputText[i]) && flag != true)
//			{
//				_outputText.push_back(_memo.back());
//				_memo.pop_back();
//			}
//			else
//				break;
//		}
//		_memo.push_back(_inputText[i]);
//	}
//	else if (_RangOperation(_inputText[i]) == 3)
//	{
//		if (_inputText[i] == "(")
//		{
//			_memo.push_back(_inputText[i]);
//			flag = true;
//		}
//		else
//		{
//			while (_memo.size() != 0)
//			{
//				if (_memo.back() == "(")
//				{
//					_memo.pop_back();
//					flag = false;
//					break;
//				}
//				_outputText.push_back(_memo.back());
//				_memo.pop_back();
//			}
//		}
//	}
//
//
//}