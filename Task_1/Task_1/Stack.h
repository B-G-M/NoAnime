#include "Memory.h"


class Stack
{
public:

	Stack();
	~Stack();

	void PushFront(int size);
	void Delete();
	void Print();

private:
	Memory List;

};

