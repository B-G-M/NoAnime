#include "Memory.h"
#include "Queue.h"


Queue::Queue()
{
}

Queue::~Queue()
{
}

void Queue::PushFront(int size)
{
	List.PushFront(size);
}

void Queue::Delete()
{
	List.retSegmentQueue(0);
	List.PopBack();
}

void Queue::Print()
{
	List.Print();
}

