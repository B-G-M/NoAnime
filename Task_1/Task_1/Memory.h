#pragma once
#include "string"

using namespace std;

class Memory
{
public:
	Memory() {};
	~Memory();


	string PushBack(int);
	string PushFront(int);
	void Print();
	void ClearSegment(int);
	

private:
	class Segment
	{
	public:
		Segment(int);
		~Segment();


		void Print();


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
	void retSegment(int id);
	void retSegmentQueue(int id);
	void ClearSegmentQueue(int number);
};