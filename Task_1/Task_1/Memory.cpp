#include "Memory.h"
#include <iostream>

Memory::~Memory()
{
	for (int i = segmentsCount; i > 0 ; i--)
	{
		ClearSegment(i);
	}
}

string Memory::PushBack(int size)
{
	if (size >= maxSize)
		return "length_error";

	try
	{
		segment = new Segment(size);
	}
	catch (const std::exception& ex)
	{
		return ex.what();
	}
	
	segment->statusFree = false;
	memorySize += size;
	segmentsCount++;

	if (segmentsCount <= 1)
	{
		segment->pNext = segment;
		segment->pPrev = segment;
		head = segment;
		tail = segment;
		return "OK";
	}
	
	segment->pPrev = tail;
	tail->pNext = segment;
	tail = segment;
	return "OK";
}

void Memory::ClearSegment(int number)
{
	Segment* temp = head;
	for (int i = 0; i < segmentsCount; i++)
	{
		if (i == number)
			if (!temp->statusFree)
			{
				delete temp->segment;
				temp->statusFree = true;
			}
				
		temp = temp->pNext;
	}
}

void Memory::retSegment(int id)
{
	Segment *temp = head;

	for (int i = 0; i <= segmentsCount; i++)
	{
		if (i == id)
		{
			Segment& t = *temp;
			cout << endl << "Следующий элемент был выбран: " << endl;
			t.Print();
			cout << " ---------------------------------------";
		}
		temp = temp->pNext;
	}
}

Memory::Segment::Segment(int size)
{
	segmentSize = size;
	segment = new char[size];
	this->statusFree = false;
	this->pPrev = nullptr;
	this->pNext = nullptr;
}

Memory::Segment::~Segment()
{
}

string Memory::PushFront(int size)
{
	if (size >= maxSize)
		return "length_error";

	try
	{
		segment = new Segment(size);
	}
	catch (const std::exception& ex)
	{
		return ex.what();
	}
	
	segment->statusFree = false;
	memorySize += size;
	segmentsCount++;

	if (segmentsCount <= 1)
	{
		segment->pNext = segment;
		segment->pPrev = segment;  
		head = segment;
		tail = segment;
		return "OK";
	}

	segment->pNext = head;
	head->pPrev = segment;   
	head = segment;
	return "OK";

}

void Memory::Print()
{
	Segment *temp = head; 
	Segment &print = *head;

	for (int i = 0; i < segmentsCount; i++)
	{
		print.Print(); 
		temp = temp->pNext;
		print = *temp;
	}
}

void Memory::Segment::Print()
{
	cout << endl << "Размер сегмента: " << segmentSize << endl;
	
	if (statusFree)
		cout << "Статус сегмента: Cвободен" << endl;
	else 
		cout << "Статус сегмента: Используется" << endl;

	cout << "Сегмент: " << segment << endl;
}


void Memory::ClearSegmentQueue(int number)
{
	Segment* temp = tail;
	for (int i = segmentsCount; i >= 0; i--)
	{
		if (i == number)
			if (!temp->statusFree)
			{
				delete temp->segment;
				temp->statusFree = true;
			}
		temp = temp->pNext;
	}
}

void Memory::PopBack()
{
	Segment* temp = tail;
	for (int i = segmentsCount; i >= 1; i--)
	{
		if (!tail->statusFree)
			ClearSegment(i);
		temp = temp->pPrev;
	}
}
void Memory::PopFront()
{
	Segment* temp = head;
	for (int i = 1; i <= segmentsCount; i++)
	{
		if (!temp->statusFree)
			ClearSegment(i);
		temp = temp->pNext;
	}
}

void Memory::retSegmentQueue(int id)
{
	Segment* temp = tail;

	for (int i = segmentsCount; i >= 0; i--)
	{
		if (i == id)
		{
			Segment& t = *temp;
			cout << endl << "Следующий элемент был выбран: " << endl;
			t.Print();
			cout << " ---------------------------------------";

		}
		temp = temp->pNext;
	}
	
}

