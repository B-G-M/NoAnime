#include "Translation.h"
#include <iostream>
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "PolishInversion.h"


using namespace std;

void Translation::FileReader(string fileName)
{
	ifstream reader(fileName);
	string str;
	try
	{
		if (reader.is_open())
		{
			while (!reader.eof())
			{
				getline(reader, str);
				_file.push_back(str);
			}
		}
		else
			throw exception("������ ������ ����� ");
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
		abort();
	}

	reader.close();
}

void Translation::Start()
{
	FileReader("CODE.txt");
	while(_file.size()!=0)
	{
		_LineReading();
		_Execution();
		_LineClean();
	}
}

void Translation::_LineReading()
{
	string buffer = "";
	for(int i = 0; i < _file.front().size(); i++)
	{
		if (_file.front()[i] == ' '|| _file.front()[i] == '(' || _file.front()[i] == ')')
		{
			_line.push_back(buffer);
			buffer = "";
			continue;
		}
		buffer += _file.front()[i];
	}
	_line.push_back(buffer);
	_file.pop_front();
}

void Translation::_LineClean()
{
	_line.clear();
}

bool Translation::_VarReVal(string name, string value)
{
	for (auto iter = _variable.begin(); iter != _variable.end(); iter++)
	{
		if (iter->name == name)
		{
			iter->value = value;
			return true;
		}
	}
	return false;
}

void Translation::_Execution()
{
	if (_line[0] == "double")
	{
		Variable temp;
		temp.name = _line[1];
		temp.type = "double";
		_variable.push_back(temp);
	}
	else if (_line[0] == "input")
	{
		string a;
		cin >> a;
		_VarReVal(_line[1], a);
	}
	else if (_line[0] == "output")
	{
		for (auto iter = _variable.begin(); iter != _variable.end(); iter++)
		{
			if (iter->name == _line[1])
			{
				cout << iter->value;
			}
		}
	}
	else
	{
		string a = "";
		PolishInversion c;
		for (int i = 0; i < _line.size(); i++)
		{
			if (_line[i] == "=")
			{
				for (int j = i+1; j < _line.size(); j++)
				{
					if (_VariableCheck(_line[j]) != "NoOne")
					{
						a += _VariableCheck(_line[j]);
					}
					else
					{
						a += _line[j];
					}
					a += " ";
				}
				a.resize(a.size() - 1);
				a = c.Translate(a);
				break;
			}
		}
		_VarReVal(_line[0], a);
	}
}

bool Translation::_AlphCheck(string check)
{
	for (auto iter = _alphabet.begin(); iter != _alphabet.end(); iter++)
	{
		if (*iter == check)
			return true;
	}
	return false;
}

string Translation::_VariableCheck(string check)
{
	for (auto iter = _variable.begin(); iter != _variable.end(); iter++)
	{
		if (iter->name == check)
		{
			return iter->value;
		}
	}
	return "NoOne";
}
