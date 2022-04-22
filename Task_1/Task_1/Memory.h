#pragma once
#include <vector>
#include "Segment.h"

class Memory
{
public:
	Memory() {};
	~Memory();
	Segment NewSegment(int bufferSize);
	void DeleteSegment(int segmentNumber);

private:
	std::vector<Segment> pool;
};