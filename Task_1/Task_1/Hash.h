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
	int hashFunction(string key);
	void AddCell(string key, T data = T());
	void Delete(string key);

private:
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
int Hash<T>::hashFunction(string key)
{
	int id = 0;
	char word;
	for (size_t i = 0; i < key.length(); i++)
	{
		id += key[i];
	}
	if (id < 0)
		id *= -1;

	return id % size;
}

template<typename T>
void Hash<T>::AddCell(string key, T data)
{
	int id = hashFunction(key);
	Cell<T>* temp = table[id];

	if (table[id]->isDelete)
	{
		table[id] = new Cell<T>(key, data);
		return;
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
}


template<typename T>
void Hash<T>::Delete(string key)
{
	int id = hashFunction(key);
	Cell<T>* temp = table[id];

	while (true)
	{
		if (key == temp->key)
		{
			temp->isDelete = true;
			break;
		}
		if (temp->collision == nullptr)
			break;

		temp = temp->collision;
	}
}