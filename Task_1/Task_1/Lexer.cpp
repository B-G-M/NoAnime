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


list <string> Lexer::FileReader()
{
	ifstream file;
	string path = "ForLexer.txt";
	list <string> input;
	string str;
	file.open(path);
	if (file.is_open())
	{
		while (file.eof())
		{
			getline(file, str);
			input.push_back(str);
		}
	}
	else
		throw exception("Ошибка чтения файла ");
	 
	file.close();
	return input;
}

string* Lexer::GetStates()
{

	/*return _sta;*/
}

string* Lexer::GetAlphabet()
{

	return _alphabet;
}

Hash<int> Lexer::GetTransitions()
{
	return _transitions;
}

void Lexer::StringAnalyzer()
{
	string temp;
	int j = 0;
	list<string> text = FileReader();
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
					_alphabet[j] = temp;
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
						_finalStates[j] = stoi(temp);
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
				for (; i < str.size(); i++)
				{
					i++;
					temp = "";
					for (; i < str.size(); i++)
					{
						if (str[i] != '(') 
						{
							//записываем состояние
						}
						else
						{

						}
					}
				}
			}
			else if (temp == "text:")
			{
				i++;
				temp = "";
				for (; i < str.size(); i++)
				{	
					for (; i < str.size(); i++)
					{
						_text += str[i];
					}
				}
			}
		}
	}
}
