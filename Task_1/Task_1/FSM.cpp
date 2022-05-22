#include "FSM.h"
#include "Lexer.h"

FSM::FSM(Lexer lexer)
{
	_alphabet = lexer.GetAlphabet();
	_currenttState = lexer.GetStartState();
	_finalStates = lexer.GetFinalStates();
	_transitions = lexer.GetTransitions();
	_text = lexer.GetText();
}


string FSM::test()
{
	for (size_t i = 0; i < _text.size(); i++)
	{
		_CheckWordInAlphabet(_text[i]);
		_ChangeState(_text[i]);
	}
	for (size_t i = 0; i < _finalStates.size(); i++)
	{
		if (_currenttState == _finalStates[i])
			return "ok";
	}
	throw exception("Не достигнуто конечное состояние");

}

bool FSM::_CheckExistTransition(int state, string word)
{
	//string ex = "Некорректная лексема" + word;
	if (_transitions.InHash(word) == false)
		throw exception(("Некорректная лексема: {}", word).data());
	//ex = "Некорректное состояние" + state;
	if (_transitions.InHash(word, state) == false)
		return false;
		//throw exception(("Некорректное состояние: {}",to_string(state)).data());
	return true;
}

bool FSM::_CheckWordInAlphabet(string word)
{
	for (size_t i = 0; i < _text.size(); i++)
	{
		if (word == _text[i])
			return true;
	}
	throw exception(("Некорректная лексема: {}", word).data()); 
}

void FSM::_ChangeState(string word)
{
	if (_CheckExistTransition(_currenttState, word))	
		_currenttState = _transitions.GetData(_currenttState, word);
	else
		throw exception(("Не существует перехода из состояния {} для {}", to_string(_currenttState), word).data());
}
