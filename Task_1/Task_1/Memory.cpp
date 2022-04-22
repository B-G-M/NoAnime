#include "Memory.h"

Memory::~Memory()
{
	for (int i = segmentsCount; i > 0 ; i--)
	{
		ClearSegment(i);
	}
}

int Memory::AddSegment(int size)
{
	if (size >= maxSize)
		return -1;
	segment = new Segment(size);
	segment->statusFree = false;
	segment->upperLink = previous;
	previous = segment;
	memorySize += size;
	segmentsCount++;
	return 0;
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
				
		temp = temp->upperLink;
	}
}

Memory::Segment::Segment(int size)
{
	segmentSize = size;
	segment = new char[size];
	this->statusFree = false;
	this->upperLink = nullptr;
}

Memory::Segment::~Segment()
{
}

