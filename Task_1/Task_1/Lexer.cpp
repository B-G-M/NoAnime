#include "Lexer.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <list>
using namespace std;


Lexer::Lexer()
{
	FileReader();
}

void Lexer::FileReader()
{
	ifstream file("ForLexer.txt");
	string str;
	try
	{
		if (file.is_open())
		{
			while (!file.eof())
			{
				getline(file, str);
				text.push_back(str);
			}
		}
		else
			throw exception("Ошибка чтения файла ");
	}
	catch (const std::exception&ex)
	{
		cout << ex.what();
		abort();
	}
	
	file.close();
}

int Lexer::GetStatesCount()
{

	return _statesCount;
}

int Lexer::GetStartState()
{
	return _startState;
}

vector<string> Lexer::GetText()
{
	return _text;
}

vector<string> Lexer::GetAlphabet()
{
	return _alphabet;
}

vector<int> Lexer::GetFinalStates()
{
	return _finalStates;
}

Hash<int>* Lexer::GetTransitions()
{
	return &_transitions;
}

void Lexer::StringAnalyzer()
{
	string temp;
	int j = 0;
	for (string str : text)
	{
		for (int i = 0; i < str.size(); i++)
		{
			temp += str[i];
			if (temp == "alphabet:")
			{
				i++;
				temp = "";
				for (;i < str.size(); i++)
				{
					if (str[i] == ',')
						continue;
					for (; i < str.size(); i++)
					{
						temp += str[i];
					}
					_alphabet.push_back(temp);
					j++;
					temp = "";
				}
				j = 0;
			}
			else if (temp == "states:")
			{
				i++;
				temp = "";
				for (; i < str.size(); i++)
				{
					for (; i < str.size(); i++)
					{
						temp += str[i];
					}
					try 
					{
						_statesCount = stoi(temp);
					}
					catch (exception &ex)
					{
						throw ex.what();
					}
					temp = "";
				}
			}
			else if (temp == "startState:")
			{
				i++;
				temp = "";
				for (; i < str.size(); i++)
				{
					for (; i < str.size(); i++)
					{
						temp += str[i];
					}
					try
					{
						_startState = stoi(temp);
					}
					catch (exception& ex)
					{
						throw ex.what();
					}
					temp = "";
				}
			}
			else if (temp == "finalState:")
			{
				i++;
				temp = "";
				for (; i < str.size(); i++)
				{
					for (; i < str.size(); i++)
					{
						temp += str[i];
					}
					try
					{
						_finalStates.push_back(stoi(temp));
						j++;
					}
					catch (exception& ex)
					{
						throw ex.what();
					}
					temp = "";
				}
				j = 0;
			}
			else if (temp == "transitions:")
			{
				i++;
				int id = 0;
				int data = 0;
				string key;
				for (; i < str.size(); i++)
				{
					temp = "";
					for (; i < str.size(); i++)
					{
						if (str[i] == '(')
							break;
						temp += str[i];

					}
					id = stoi(temp);
					temp = "";
					i++;
					for (; i < str.size(); i++)
					{
						if (str[i] == ')')
							break;
						if (str[i] == ':')
						{
							i++;
							for (; i < str.size(); i++)
							{
								if (str[i] == ',' || str[i] == ')')
									break;
								temp += str[i];
							}
							data = stoi(temp);
							temp = "";
							_transitions.AddState(id, key, data);
							key = "";
							if (str[i] == ')')
								break;
							i++;
							
						}
						key += str[i];
					}
				}
				temp = "";
			}
			else if (temp == "text:")
			{
				i++;
				for (; i < str.size(); i++)
				{	
					temp = "";
					for (; i < str.size(); i++)
					{
						if (str[i] == ',')
							break;
						temp += str[i];
					}
					_text.push_back(temp);
				}
				temp = "";
			}
		}
	}
}
