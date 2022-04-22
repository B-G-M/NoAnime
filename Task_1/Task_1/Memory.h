#pragma once
#include <vector>

using namespace std;

class Memory
{
public:
	Memory() {};
	~Memory();

	int AddSegment(int);
	void ClearSegment(int);

private:
	class Segment
	{
	public:
		Segment(int);
		~Segment();

		int	segmentSize;
		bool statusFree;
		char* segment;
		Segment* upperLink;
	};

	int memorySize;
	int segmentsCount;

	const int maxSize = 1024;

	Segment* segment;
	Segment* previous = nullptr;
};