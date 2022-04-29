#include "Memory.h"

Memory::~Memory()
{
	for (int i = segmentsCount; i > 0 ; i--)
	{
		ClearSegment(i);
	}
}

string Memory::AddSegment(int size)
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
	Segment* temp = segment;
	for (int i = segmentsCount; i >= number; i--)
	{
		if (i == number)
			if (!temp->statusFree)
			{
				delete temp->segment;
				temp->statusFree = true;
			}
				
		temp = temp->pPrev;
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

