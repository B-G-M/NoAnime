#include "Memory.h"
#include "Queue.h"



Queue::Queue()
{
}



Queue::~Queue()
{
}



string Queue::PushFront(int size)
{
	return List.PushFront(size);
}



string Queue::Delete()
{
	return List.PopBack();
}



string Queue::Print()
{
	return List.Print();
}



void Queue::Clear(int number)
{
	List.ClearSegment(number);
}

