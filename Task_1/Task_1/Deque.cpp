#include "Deque.h"
#include "Memory.h"
#include <iostream>

Deque::Deque()
{

}

Deque::~Deque()
{

}

void Deque::PushFront(int size)
{
	List.PushFront(size);
}

void Deque::PushBack(int size)
{
	List.PushBack(size);
}

void Deque::PopBack()
{
	if (List.GetSegmentsCount() == 0)
	{
		Err();
		return;
	}
	List.PopBack();
}

void Deque::PopFront()
{
	if (List.GetSegmentsCount() == 0)
	{
		Err();
		return;
	}
	List.PopFront();
}

void Deque::Print()
{
	List.Print();
}

void Deque::Err()
{
	cout <<endl<< "Невозможно удалить элемент из пустого дека" << endl;
}

void Deque::Clear(int number)
{
	List.ClearSegment(number);
}
