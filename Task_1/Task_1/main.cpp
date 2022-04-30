#include <iostream>
#include <windows.h>
#include "Memory.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string exception;
	Memory memory;
	Stack stack;
	Queue queue;

	/*memory.PushBack(8);
	memory.PushBack(3);
	memory.PushBack(9);
	memory.PushBack(5);
	memory.PushBack(1);

	memory.ClearSegment(2);
	memory.ClearSegment(4);
	memory.ClearSegment(3);

	memory.PushBack(1024);

	memory.PushBack(512);
	memory.PushBack(512);
	memory.PushBack(512);*/

	
	stack.PushFront(1);
	stack.PushFront(7);
	stack.PushFront(3);
	stack.Delete();
	stack.Print();


	/*queue.PushFront(1);
	queue.PushFront(5);
	queue.PushFront(3);
	queue.Delete();
	queue.Print();*/

	return 0;
}


