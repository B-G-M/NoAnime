#include "Memory.h"

Memory::~Memory()
{
	for (int i = 0; i < pool.size(); i++)
	{
		pool[i].Delete();
	}
}

Segment Memory::NewSegment(int bufferSize)
{
	Segment segment(bufferSize);
	
	if (pool.size() > 0)
		segment.SetUpperSegment(&pool[pool.size() - 1]);

	pool.push_back(segment);

	return segment;
}

void Memory::DeleteSegment(int segmentNumber)
{
	pool[segmentNumber - 1].Delete();
}