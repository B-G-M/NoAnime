#include <iostream>
#include <vector>
#include "windows.h";

using namespace std;

class Memory
{
public:
	Memory();
	~Memory();
	char* NewSegment(int bufferSize);
	void DeleteSegment();
	void DeleteSegment(int segmentNumber);

private:
	char* segment;
	vector<char*> pool;


}; 

Memory::~Memory()
{
	delete segment;
}

char* Memory::NewSegment(int bufferSize)
{
	segment = new char[bufferSize];
	pool.push_back(segment);
	return segment;
}

void Memory::DeleteSegment()
{
	delete this->segment;
}

void Memory::DeleteSegment(int segmentNumber)
{
	cout << "Сегмент " << segmentNumber << "удален" << endl;
	delete pool[segmentNumber - 1];
	//pool.erase(pool.begin()+segmentNumber--);
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Memory memory;

	memory.NewSegment(8);
	memory.NewSegment(3);
	memory.NewSegment(9);
	memory.NewSegment(5);
	memory.NewSegment(1);

	memory.DeleteSegment(2);
	memory.DeleteSegment(2);

	return 0;
}


