#include "Deque.h"
#include "Memory.h"
#include <iostream>



Deque::Deque()
{

}



Deque::~Deque()
{

}



string Deque::PushFront(int size)
{
	return List.PushFront(size);
}



string Deque::PushBack(int size)
{
	return List.PushBack(size);
}



string Deque::PopBack()
{
	if (List.GetSegmentsCount() == 0)
	{
		return Err();
	}
	return List.PopBack();
}



string Deque::PopFront()
{
	if (List.GetSegmentsCount() == 0)
	{
		return Err();
	}
	return List.PopFront();
}



string Deque::Print()
{
	return List.Print();
}



string Deque::Err()
{
	return "Невозможно удалить элемент из пустого дека\n";
}



void Deque::Clear(int number)
{
	List.ClearSegment(number);
}