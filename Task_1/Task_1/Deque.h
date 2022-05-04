#pragma once
#include "Memory.h"



class Deque
{
public:
	Deque();
	~Deque();

	string PushFront(int size);
	string PushBack(int size);
	string PopBack();
	string PopFront();
	string Print();
	string Err();
	void Clear(int number);

private:
	Memory List;
};

