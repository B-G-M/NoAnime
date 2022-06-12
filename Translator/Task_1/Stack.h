#include "Memory.h"



class Stack
{
public:

	Stack();
	~Stack();

	string PushFront(int size);
	string Delete();
	string Print();
	void Clear(int number);

private:
	Memory List;

};

