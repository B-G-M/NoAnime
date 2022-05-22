#pragma once
#include "string"

using namespace std;

class Memory
{
public:
	Memory() {};
	~Memory();

private:
	class Segment
	{
	public:
		Segment(int);
		~Segment();

		string Print();

		int	segmentSize;
		bool statusFree;
		char* segment;
		Segment* pNext = nullptr;
		Segment* pPrev = nullptr;
	};

	int memorySize;
	int segmentsCount;

	const int maxSize = 1024;

	Segment* segment;

	Segment* head = nullptr;
	Segment* tail = nullptr;

public:

	string PushBack(int);
	string PushFront(int);
	string PopBack();
	string PopFront();

	string Print();
	void ClearSegment(int);
	string retSegment(Segment print);
	int GetSegmentsCount();

};