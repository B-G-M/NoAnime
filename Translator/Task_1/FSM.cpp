#include "FSM.h"
#include "Lexer.h"
#include <iostream>
using namespace std;

FSM::FSM(string fileName)
{
	lexer.StringAnalyzer(fileName);
	_alphabet = lexer.GetAlphabet();
	_currentState = lexer.GetStartState();
	_finalStates = lexer.GetFinalStates();
	_transitions = lexer.GetTransitions();
	path += "start -> ";
}


string FSM::test(string text)
{
	try
	{
		_currentState = lexer.GetStartState();
		_text = text;
		string word;
		string var;
		for (size_t i = 0; i <= _text.size(); i++)
		{
			if (_text[i] == ' ' || _isSymbol(_text[i], word))
			{
				while (_text[i] == ' ')
					i++;
				if (_CheckWordInAlphabet(word))
					_ChangeState(word);
				else if (_CheckWordInAlphabet("var"))
				{
					if (!_ChangeState("var"))
						throw exception(("Некорректная лексема: " + word).data());
				}
				else
					throw exception(("Некорректная лексема: " + word).data());
				word = "";
			}
			word += _text[i];
		}
		for (size_t i = 0; i < _finalStates.size(); i++)
		{
			if (_currentState == _finalStates[i])
				return path + "end";
		}
		throw exception("Не достигнуто конечное состояние");
	}
	catch (const std::exception& ex)
	{
		return ex.what();
	}
}

bool FSM::_CheckExistTransition(int state, string word)
{
	if (_transitions->InHash(state,word) == false)
		return false;
	return true;
}

bool FSM::_CheckWordInAlphabet(string word)
{
	for (size_t i = 0; i < _alphabet.size(); i++)
	{
		if (word == _alphabet[i])
			return true;
	}
	return false;
}

bool FSM::_ChangeState(string word)
{

	if (_CheckExistTransition(_currentState, word))
	{
		path += "s:" + to_string(_currentState) + "|w:" + word + " -> ";
		_currentState = _transitions->GetData(_currentState, word);
		return true;
	}
	else if (word != "var")
		throw exception(("Не существует перехода из состояния " + to_string(_currentState) + " для " + word).data());
	else
		return false;
}

bool FSM::_isSymbol(char symbol1, string symbol2)
{
	int code1 = (int)symbol1;
	if (code1 == 46)
		return false;
	if (code1 >= 33 && code1 <= 47)
		return true;
	if (code1 == 59)
		return true;

	if (symbol2.size() == 1)
	{
		int code2 = (int)symbol2[0];
		if (code2 == 46)
			return false;
		if (code2 >= 33 && code2 <= 47)
			return true;
		if (code2 == 59)
			return true;
	}
	return false;
}
