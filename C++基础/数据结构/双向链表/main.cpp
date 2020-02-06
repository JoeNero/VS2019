/*
文件名 	:   main.cpp
创建者	:	XTT
功能	:	One-way linked list
			单向链表
			有bug 内存泄漏 
			析构函数中,头节点未释放

时间	:	2020/02/05
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
		cout << "输入插入的数据";
		cin >> data;
		pushBack(head, data);
		printList(head);
		cout << getLength(head);
		//cout << "移除的数据" << endl;
		//cin >> data;
		//remove(head,data);
		//printList(head);
	}
}
