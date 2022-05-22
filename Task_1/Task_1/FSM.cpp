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
	throw exception("�����");

}

bool FSM::_CheckExistTransition(int state, string word)
{
	//string ex = "������������ �������" + word;
	if (_transitions.InHash(word) == false)
		throw exception(("������������ �������: {}", word).data());
	//ex = "������������ ���������" + state;
	if (_transitions.InHash(word, state) == false)
		return false;
		//throw exception(("������������ ���������: {}",to_string(state)).data());
	return true;
}

void FSM::_ChangeState(string word)
{
	if (_CheckExistTransition(_currenttState, word))	
		_currenttState = _transitions.GetData(_currenttState, word);
	else
		throw exception(("�� ���������� �������� �� ��������� {} ��� {}", to_string(_currenttState), word).data());
}
