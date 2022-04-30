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
	void Delete();
	void Print();

private:
	Memory List;

};

