#include "Lexer.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <list>

using namespace std;


void Lexer::FileReader(string fileName)
{
	ifstream file(fileName);
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


int Lexer::GetStartState()
{
	return _startState;
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

void Lexer::StringAnalyzer(string fileName)
{
	FileReader(fileName);
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
					for (; i < str.size(); i++)
					{
						if (str[i] == ',')
							break;
						temp += str[i];
					}
					_alphabet.push_back(temp);
					temp = "";
				}
				j = 0;
			}
			else if (temp == "startState:")
			{
				i++;
				temp = "";
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
					cout << ex.what();
					abort();
				}
				temp = "";
			}
			else if (temp == "finalStates:")
			{
				i++;
				temp = "";
				for (; i < str.size(); i++)
				{
					for (; i < str.size(); i++)
					{
						if (str[i] == ',')
							break;
						temp += str[i];
					}
					try
					{
						_finalStates.push_back(stoi(temp));
					}
					catch (exception& ex)
					{
						cout << ex.what();
						abort();
					}
					temp = "";
				}
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
						if (str[i] == ')' && str[i - 1] != '(')
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
		}
	}
}
