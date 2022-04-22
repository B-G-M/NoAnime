#pragma once

class Segment
{
public:
	Segment(int bufferSize);
	~Segment();
	
	int GetSize();
	void SetSize(int bufferSize);

	bool GetStatus();
	void SetStatus(bool status);

	char* GetSegment();

	Segment* GetUpperSegment();
	void SetUpperSegment(Segment* upperSegment);

	void Delete();

	Segment& operator=(Segment);

private:
	char* segment;
	int size;
	bool statusFree;
	Segment* upperSegment;
};