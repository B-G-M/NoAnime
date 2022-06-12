#include <iostream>
#include <windows.h>
#include "Memory.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "Lexer.h"
#include "Hash.h"
#include "FSM.h"
#include "PolishInversion.h"
#include "Translation.h"

#include<string>
#include<list>

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



	//Стек

	/*cout << stack.PushFront(1) << endl;
	cout << stack.PushFront(7) << endl;
	cout << stack.PushFront(3) << endl;
	cout << stack.PushFront(5) << endl;
	cout << stack.PushFront(2) << endl;

	system("pause");
	system("cls");
	
	stack.Clear(0);
	cout << stack.PushFront(9);
	cout << stack.Delete();

	system("pause");
	system("cls");

	cout << stack.Print();*/



	//Очередь

	//cout << queue.PushFront(1) << endl;
	//cout << queue.PushFront(5) << endl;
	//cout << queue.PushFront(3) << endl;
	//cout << queue.PushFront(7) << endl;

	//system("pause");
	//system("cls");

	//queue.Clear(0);
	//cout << queue.Delete();

	//system("pause");
	//system("cls");

	//cout << queue.Print();



	//Дек

	/*cout << deque.PushFront(4) << endl;
	cout << deque.PushFront(7) << endl;
	cout << deque.PushBack(5) << endl;

	system("pause");
	system("cls");

	deque.Clear(0);
	cout << deque.PopFront();
	cout << deque.PopBack();
	cout << deque.PopBack();
	cout << deque.PopBack();
	cout << deque.PopFront();
	cout << deque.PopBack();
	cout << deque.PopBack();

	system("pause");
	system("cls");

	deque.Print();*/

	//Hash

	//Hash<string> hash;

	//hash.AddCell("Ананас");
	//hash.AddCell("Петрушка");
	//hash.AddCell("Банан");
	//hash.AddCell("Персик");
	//hash.DeleteCell("Ананас");
	//hash.InHash("Петрушка");
	//for (size_t i = 0; i < 8; i++)
	//{
	//	hash.table[i];
	//}
	
	/*PolishInversion a;
	cout << a.Translate("8 + 2 * (5 + 7) + 2");*/

	Translation a;
	a.Start();
	return 0;
}


