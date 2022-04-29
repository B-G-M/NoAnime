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
	List.ClearSegment(1);
	List.retSegmentQueue(1);
}

void Queue::Print()
{
	List.Print();
}

