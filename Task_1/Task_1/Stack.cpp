#include "Stack.h"
#include "Memory.h"



Stack::Stack()
{
}



Stack::~Stack()
{
}



string Stack::Print()
{
	return List.Print();
}



void Stack::Clear(int number)
{
	List.ClearSegment(number);
}



string Stack::PushFront(int size)
{
	return List.PushFront(size);
}



string Stack::Delete()
{
	return List.PopFront();
}

