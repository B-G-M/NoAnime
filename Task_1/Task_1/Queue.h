#include "Memory.h"



class Queue
{
public:
	Queue();
	~Queue();

	string PushFront(int size);
	string Delete();
	string Print();
	void Clear(int number);

private:
	Memory List;
};



