/*
�ļ��� 	:   main.cpp
������	:	XTT
����	:	One-way linked list
			��������

ʱ��	:	2020/02/05
*/
#define CRTDBG_MAP_ALLOC  
#include <iostream>
#include <crtdbg.h> 
#include "List.h"

using namespace std;

void test();

int main()
{
//	_CrtSetBreakAlloc(154);
//	_CrtSetBreakAlloc(250);
	test();
	_CrtDumpMemoryLeaks();
	return 0;
}

void test()
{
	Node* head = createList();
	for (int i = 0; i < 20; i++)
	{
		pushBack(head, i);
	}
	printList(head);
	head = reverse(head);
	printList(head);
	destroy(head);
}
