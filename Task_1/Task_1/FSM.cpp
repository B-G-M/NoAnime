#include "FSM.h"
#include "Lexer.h"

FSM::FSM(Lexer lexer)
{
	
}


FSM::~FSM()
{
	//delete[] _states;
	delete[] _alphabet;
	delete[] _finalStates;
}

string FSM::test()
{
	for (size_t i = 0; i < _sizeAlphabet; i++)
	{
		_ChangeState(_alphabet[i]);
	}
	for (size_t i = 0; i < _sizeFinalStates; i++)
	{
		if (_currenttState == _finalStates[i])
			return "ok";
	}
	throw exception("Хуета");

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

void FSM::_ChangeState(string word)
{
	if (_CheckExistTransition(_currenttState, word))	
		_currenttState = _transitions.GetData(_currenttState, word);
	else
		throw exception(("Не существует перехода из состояния {} для {}", to_string(_currenttState), word).data());
}
