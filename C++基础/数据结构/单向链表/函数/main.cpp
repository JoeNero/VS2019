/*
�ļ��� 	:   main.cpp
������	:	XTT
����	:	One-way linked list
			��������
			��bug �ڴ�й© 
			���������ڴ�й¶
			��ȡ���ȣ��ڴ�й¶

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
