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
	//Segment* temp = head;
	for (int i = 0; i < segmentsCount; i++)
	{
		PopBack1();
		/*if (i == number - 1)
			if (!temp->statusFree)
			{
				delete temp->segment;
				temp->statusFree = true;
			}
		if(i < segmentsCount)
			temp = temp->pNext;*/	
	}
}

void Memory::retSegment(Segment print)
{
	cout << endl << "Следующий новичок был кикнут из команды: " << endl;
	print.Print();
	cout << " ---------------------------------------";
}

int Memory::GetSegmentsCount()
{
	return segmentsCount;
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
		if (i != segmentsCount - 1)
		{
			temp = temp->pNext;
			print = *temp;
		}
		
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


void Memory::PopBack()
{
	Segment* temp = tail;
	retSegment(*temp);
	tail = temp->pPrev;
	tail->pNext = tail;
	
	memorySize -= temp -> segmentSize;
	delete temp;
	segmentsCount--;
}

void Memory::PopBack1()
{
	Segment* temp = tail;
	tail = temp->pPrev;
	tail->pNext = tail;

	memorySize -= temp->segmentSize;
	delete temp;
	segmentsCount--;
}
void Memory::PopFront()
{
	Segment* temp = head;
	retSegment(*temp);
	head = temp->pNext;
	head->pPrev = head;
	
	memorySize -= temp->segmentSize;
	delete temp;
	segmentsCount--;
}



