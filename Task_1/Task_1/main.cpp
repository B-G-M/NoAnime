#include <iostream>
#include <vector>
#include "windows.h";
#include "Memory.h"

using namespace std;

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
	memory.DeleteSegment(4);
	return 0;
}


