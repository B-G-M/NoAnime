#include "Memory.h"
#include "Stack.h"

class Queue
{
public:
	Queue();
	~Queue();

	void PushFront(int size);
	void Delete();

	void Print();

private:
	Memory List;
};
