#pragma once
#include <string>
#include <list>
#include <optional>

using namespace std;

template<typename T>
class Cell
{
public:
	Cell(string key, T data = T())
	{
		this->_data = data;
		this->_key = key;
	};
	~Cell() {};
	T GetData(){ return _data; }
	string GetKey(){ return _key; }
private:
	T _data;
	string _key;
};

template<typename T>
class Hash
{
public:
	Hash()
	{
		table = new list<Cell<T>>[size];
	};
	Hash(int size)
	{
		table = new list<Cell<T>>[size];
	}
	~Hash()
	{
		delete[] table;
	};

	int size = 15;
	list<Cell<T>>* table;
	list<Cell<T>> operator[] (int index);
	int GetSize() { return size; };
	void AddState(int i, string key, T data);
	int AddCell(string key, T data = T());
	bool InHash(int id,string key);
	string DeleteCell(string key); 
	T GetData(int id, string key);
private:
	int _cellCount = 0;
	void _ReSize();
	int _HashFunction(string key);
	
};

template<typename T>
int Hash<T>::_HashFunction(string key)
{
	int id = 0;
	for (size_t i = 0; i < key.length(); i++)
	{
		id += key[i];
	}
	if (id < 0)
		id *= -1;

	return id % size;
}

template<typename T>
inline void Hash<T>::_ReSize()
{
	size *= 2;
	list<Cell<T>>* temp = new list<Cell<T>>[size];

	for (size_t i = 0; i < size / 2; i++)
	{
		for (Cell<T> cell : table[i])
		{
			temp[_HashFunction(cell.GetKey())].push_back(cell);
		}
	}
	delete[] table;
	table = temp;
}

template<typename T>
inline list<Cell<T>> Hash<T>::operator[](int index)
{
	return table[index];
}

template<typename T>
void Hash<T>::AddState(int id, string key, T data)
{
	Cell<T> temp(key, data);

	table[id].push_back(temp);
	_cellCount++;
}

template<typename T>
int Hash<T>::AddCell(string key, T data)
{
	if (_cellCount == size * size)
		_ReSize();

	int id = _HashFunction(key);
	Cell<T> temp(key, data);

	table[id].push_back(temp);
	_cellCount++;
	return id;
}

template<typename T>
bool Hash<T>::InHash(int id, string key)
{
	for (auto cell = table[id].begin(); cell != table[id].end(); cell++)
	{
		if (key == cell->GetKey())
		{
			return true;
			break;
		}
	}
	return false;
}


template<typename T>
string Hash<T>::DeleteCell(string key)
{
	int id = _HashFunction(key);
	string delLog;

	for (auto cell = table[id].begin(); cell != table[id].end(); cell++)
	{
		if (key == cell->GetKey())
		{
			table[id].erase(cell);
			_cellCount--;
			return delLog = "Объект удален из хэш таблицы";
		}
	}
	return delLog = "Объект не удален из хэш таблицы";
}

template<typename T>
inline T Hash<T>::GetData(int id, string key)
{
	if (id > size)
		throw exception("Out of range");

	for (Cell<T> cell : table[id])
	{
		if (key == cell.GetKey())
			return cell.GetData();
	}
	//string ex = "Для полученного ID({}) не найден ключ({})", id, key;
	throw exception(("Для полученного ID: " + to_string(id) + " не найден ключ: "+ key).data());
}
