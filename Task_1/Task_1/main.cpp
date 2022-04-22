#include <iostream>
#include "windows.h";
#include "Memory.h"

using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Memory memory;

	memory.AddSegment(8);
	memory.AddSegment(3);
	memory.AddSegment(9);
	memory.AddSegment(5);
	memory.AddSegment(1);

	memory.ClearSegment(2);
	memory.ClearSegment(4);
	memory.ClearSegment(9);

	memory.AddSegment(1024) == -1 ? cout << "Error" << endl : cout << "OK" << endl;

	memory.AddSegment(512);
	memory.AddSegment(512);
	memory.AddSegment(512);
	return 0;
}


