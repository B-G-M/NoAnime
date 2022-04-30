#include "Stack.h"
#include "Memory.h"

Stack::Stack()
{
}
Stack::~Stack()
{
}

void Stack::Print()
{
	List.Print();
}

void Stack::PushFront(int size)
{
	List.PushFront(size);
}

void Stack::Delete() 
{
	List.retSegment(0);
	List.ClearSegment(0);
}

