#include "Segment.h"

Segment::Segment(int bufferSize)
{
	size = bufferSize;
	segment = new char[bufferSize];
	statusFree = false;
	upperSegment = nullptr;
}

Segment::~Segment()
{
	//delete segment;
}

int Segment::GetSize()
{
	return this->size;
}

void Segment::SetSize(int bufferSize)
{
	if (statusFree)
		segment = new char[bufferSize];
}

bool Segment::GetStatus()
{
	return statusFree;
}

void Segment::SetStatus(bool status)
{
	this->statusFree = status;
}

char* Segment::GetSegment()
{
	return segment;
}

Segment* Segment::GetUpperSegment()
{
	return upperSegment;
}

void Segment::SetUpperSegment(Segment* upperSegment)
{
	this->upperSegment = upperSegment;
}

void Segment::Delete()
{
	if (!statusFree) 
		delete segment;

	statusFree = true;
}

Segment& Segment::operator=(Segment a)
{
	this->size = a.size;
	this->segment = a.segment;
	this->statusFree = a.statusFree;
	this->upperSegment = a.upperSegment;
	return *this;
}
