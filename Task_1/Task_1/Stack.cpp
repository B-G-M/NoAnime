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

void Stack::Clear(int number)
{
	List.ClearSegment(number);
}

void Stack::PushFront(int size)
{
	List.PushFront(size);
}

void Stack::Delete() 
{
	List.PopFront();
}

