#include "Lexer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

Lexer::Lexer()
{
}

Lexer::~Lexer()
{
}


inline string Lexer::GetText()
{
	ifstream file;
	string path = "ForLexer.txt";
	list <char> input;
	char temp;
	file.open(path);
	if (!file.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		while (!file.eof())
		{
			file.get(temp);
			input.push_back(temp);
		}	
	}
	file.close();
	return string();
}

string* Lexer::GetStates()
{
	return _sta;
}

string* Lexer::GetAlphbet()
{
	return nullptr;
}

string** Lexer::GetTransitions()
{
	return nullptr;
}
