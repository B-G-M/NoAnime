#include <iostream>
#include <windows.h>
#include "Memory.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"

using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string exception;
	Memory memory;
	Stack stack;
	Queue queue;
	Deque deque;

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

	//
	//stack.PushFront(1);
	//stack.PushFront(7);
	//stack.PushFront(3);
	//stack.PushFront(5);
	//stack.PushFront(2);
	//stack.Clear(0);
	//stack.PushFront(9);
	//stack.Delete();
	//stack.Print();


	//queue.PushFront(1);
	//queue.PushFront(5);
	//queue.PushFront(3);
	//queue.PushFront(7);
	//queue.Clear(0);
	//queue.Delete();
	//queue.Print();

	/*deque.PushFront(4);
	deque.PushFront(7);
	deque.PushBack(5);
	deque.Clear(0);
	deque.PopFront();
	deque.PopBack();
	deque.PopBack();
	deque.PopBack();
	deque.PopFront();
	deque.PopBack();
	deque.PopBack();
	deque.Print();*/


	return 0;
}


