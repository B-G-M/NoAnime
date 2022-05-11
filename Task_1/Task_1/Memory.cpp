#include "Memory.h"
#include <string>



Memory::~Memory()
{
	for (int i = segmentsCount; i > 0; i--)
	{
		PopBack();
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
	if (number > segmentsCount)
		return;

	Segment* temp = head;
	for (int i = 0; i <= number; i++)
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



string Memory::retSegment(Segment print)
{
	string r = "\n";
	r += "Следующий элемент был удален : ";
	r += print.Print();
	r += "\n";
	r += " ---------------------------------------";
	r += "\n";
	return r;
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



string Memory::Print()
{
	Segment* temp = head;
	Segment& print = *head;
	string r = "";

	for (int i = 0; i < segmentsCount; i++)
	{
		r += print.Print();
		r += "\n\n";
		if (i != segmentsCount - 1)
		{
			temp = temp->pNext;
			print = *temp;
		}

	}
	r += "\n";
	return r;
}



string Memory::Segment::Print()
{
	string r = "";
	r += "Размер сегмента: ";
	r += std::to_string(segmentSize);
	r += "\n";
	if (statusFree)
		r += "Статус сегмента: Cвободен";
	else
		r += "Статус сегмента: Используется";
	r += "\n";
	r += "Сегмент: ";
	r += segment;
	r += "\n";
	return r;
}



string Memory::PopBack()
{
	Segment* temp = tail;
	string r = "\n";
	r += retSegment(*temp);
	tail = temp->pPrev;
	tail->pNext = tail;

	memorySize -= temp->segmentSize;
	delete temp;
	segmentsCount--;
	return r;
}



string Memory::PopFront()
{
	Segment* temp = head;
	string r = "\n";
	r += retSegment(*temp);
	head = temp->pNext;
	head->pPrev = head;

	memorySize -= temp->segmentSize;
	delete temp;
	segmentsCount--;
	return r;
}