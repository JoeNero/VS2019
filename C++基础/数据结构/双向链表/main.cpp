/*
�ļ��� 	:   main.cpp
������	:	XTT
����	:	One-way linked list
			��������
			��bug �ڴ�й© 
			����������,ͷ�ڵ�δ�ͷ�

ʱ��	:	2020/02/05
*/
#define CRTDBG_MAP_ALLOC  
#include <iostream>
#include <crtdbg.h> 
#include "DoubleLink.h"

void test();
using namespace std;

int main()
{
//	_CrtSetBreakAlloc(222);
//	_CrtSetBreakAlloc(153);

	test();
	_CrtDumpMemoryLeaks();
	return 0;
}

void test()
{
	int data;
	Node* head = createList();
	printList(head);
	while (true)
	{
		cout << "������������";
		cin >> data;
		pushBack(head, data);
		printList(head);
		cout << getLength(head);
		//cout << "�Ƴ�������" << endl;
		//cin >> data;
		//remove(head,data);
		//printList(head);
	}
}
