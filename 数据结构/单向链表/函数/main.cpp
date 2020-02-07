/*
文件名 	:   main.cpp
创建者	:	XTT
功能	:	One-way linked list
			单向链表

时间	:	2020/02/05
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
