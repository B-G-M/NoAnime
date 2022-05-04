#include "Memory.h"


class Stack
{
public:

	Stack();
	~Stack();

	void PushFront(int size);
	void Delete();
	void Print();
	void Clear(int number);

private:
	Memory List;

};

