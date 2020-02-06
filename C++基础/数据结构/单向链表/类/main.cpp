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
#include "List.h"

using namespace std;

int main()
{
//	_CrtSetBreakAlloc(222);
//	_CrtSetBreakAlloc(153);
	int n;
	cin >> n;
	if (n)
	{
		mList l1;
		for (size_t i = 0; i < 10; i++)
		{
			l1.pushBack(i);
		};
		l1.printList();
		l1.clear();
		l1.printList();
		l1.popBack();
	}

	_CrtDumpMemoryLeaks();
	return 0;
}

