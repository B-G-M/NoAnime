#pragma once
#include "Memory.h"

class Deque
{
public:
	Deque();
	~Deque();

	void PushFront(int size);
	void PushBack(int size);
	void PopBack();
	void PopFront();
	void Print();
	void Err();

private:
	Memory List;

};

