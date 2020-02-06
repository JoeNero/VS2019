/*
文件名 	:   main.cpp
创建者	:	XTT
功能	:	One-way linked list
			单向链表
			有bug 内存泄漏 
			链表销毁内存泄露
			获取长度，内存泄露

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
//	_CrtSetBreakAlloc(252);

	test();
	_CrtDumpMemoryLeaks();
	return 0;
}

void test()
{
	Node* head = new Node;
	head = createList();
	for (int i = 0; i < 20; i++)
	{
		pushBack(head, i);
	}
	printList(head);
	cout << "len =" << getLength(head) << endl;
	destroy(head);
}
