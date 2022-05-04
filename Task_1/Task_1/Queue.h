#include "Memory.h"


class Queue
{
public:
	Queue();
	~Queue();

	void PushFront(int size);
	void Delete();
	void Print();
	void Clear(int number);

private:
	Memory List;
};



