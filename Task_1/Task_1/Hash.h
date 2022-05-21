#pragma once
#include <string>
#include <vector>
using namespace std;

template<typename T>
class Hash
{
public:
	Hash(int hashSize);
	~Hash();
	
	int AddCell(string key, T data = T());
	bool InHash(string key);

private:
	int _HashFunction(string key);
	string _Delete(string key);

	template<typename T>
	class Cell
	{
	public:
		Cell()
		{
			this->collision = nullptr;
			this->isDelete = true;
		};
		Cell(string key, T data = T())
		{
			this->data = data;
			this->key = key;
			this->collision = nullptr;
			this->isDelete = false;
		};
		T data;
		string key;
		Cell<T>* collision;
		bool isDelete;
	};
public:
	Cell<T>** table;
	int size;
};

template<typename T>
Hash<T>::Hash(int hashSize)
{
	size = hashSize * 2;
	table = new Cell<T>*[size]{};
	for (size_t i = 0; i < size; i++)
	{
		table[i] = new Cell<T>();
	}
}

template<typename T>
Hash<T>::~Hash()
{
	Cell<T>* temp;
	Cell<T>* prevTemp;
	int i = 0;
	while (true)
	{
		prevTemp = table[i];
		while (prevTemp->collision == nullptr)
		{
			if (i == size)
				break;
			i++;
		}
		if (i == size)
			break;

		temp = table[i]->collision;
		prevTemp = table[i];

		while (true)
		{
			if (temp->collision == nullptr)
			{
				prevTemp->collision = nullptr;
				delete temp;
				break;
			}
			temp = temp->collision;
			prevTemp = prevTemp->collision;
		}
	}
	delete[]table;
}

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
int Hash<T>::AddCell(string key, T data)
{
	int id = _HashFunction(key);
	Cell<T>* temp = table[id];

	if (temp->isDelete)
	{
		table[id] = new Cell<T>(key, data);
		return id;
	}
	while (true)
	{
		if (temp->collision == nullptr || temp->isDelete)
		{
			temp->collision = new Cell<T>(key, data);
			break;
		}
		temp = temp->collision;
	}
	return id;
}

template<typename T>
inline bool Hash<T>::InHash(string key)
{
	for (size_t i = 0; i < this.size; i++)
	{
		Cell<T>* temp = table[id];

		do
		{
			if (temp->key == key)
				return true;
			temp = temp->collision;
		} 
		while (temp->collision != nullptr);
	}
	return false;
}


template<typename T>
string Hash<T>::_Delete(string key)
{
	int id = _HashFunction(key);
	Cell<T>* temp = table[id];
	string k = "Объект не удален из хэш таблицы";
	while (true)
	{
		if (key == temp->key)
		{
			temp->isDelete = true;
			break;
			k = "Объект удален из хэш таблицы";
		}
		if (temp->collision == nullptr)
			break;

		temp = temp->collision;
	}
	return k;
}