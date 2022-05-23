#include "FSM.h"
#include "Lexer.h"
#include <iostream>
using namespace std;

FSM::FSM()
{
	lexer.StringAnalyzer();
	_alphabet = lexer.GetAlphabet();
	_currentState = lexer.GetStartState();
	_finalStates = lexer.GetFinalStates();
	_transitions = lexer.GetTransitions();
	_text = lexer.GetText();
	path += "start: ";
}


string FSM::test()
{
	try
	{
		for (size_t i = 0; i < _text.size(); i++)
		{
			_CheckWordInAlphabet(_text[i]);
			_ChangeState(_text[i]);
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
	for (size_t i = 0; i < _text.size(); i++)
	{
		if (word == _text[i])
			return true;
	}
	throw exception(("Некорректная лексема: "+ word).data()); 
}

void FSM::_ChangeState(string word)
{

	if (_CheckExistTransition(_currentState, word))
	{
		path += to_string(_currentState) + "->";
		_currentState = _transitions->GetData(_currentState, word);
	}
	else
		throw exception(("Не существует перехода из состояния " + to_string(_currentState) + " для "+ word).data());
}
