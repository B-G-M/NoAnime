#include <iostream>
#include "windows.h";
#include "Memory.h"
#include "Stack.h"

using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string exception;
	Memory memory;
	Stack stack;

	memory.PushBack(8);
	memory.PushBack(3);
	memory.PushBack(9);
	memory.PushBack(5);
	memory.PushBack(1);

	memory.ClearSegment(2);
	memory.ClearSegment(4);
	memory.ClearSegment(3);

	cout << memory.PushBack(1024);

	memory.PushBack(512);
	memory.PushBack(512);
	memory.PushBack(512);

	
	stack.PushFront(1);
	stack.PushFront(7);
	stack.PushFront(3);
	stack.PushFront(5);
	stack.PushFront(1);
	stack.PushFront(4);

	stack.Delete();
	stack.Print();

	return 0;
}


