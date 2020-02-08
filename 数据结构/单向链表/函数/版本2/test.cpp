/*
创建者	:	XTT
功能	:


时间	:	2020/02/07
*/
#define CRTDBG_MAP_ALLOC  
#include <iostream>
#include "Linklist.h"

using namespace std;

int main()
{
	LinkList* head = new LinkList;
	Elemtype data = 0;
	Elemtype& p = data;
	InitList(head);
	for (size_t i = 0; i < 13; i++)
	{
		//pushFront(head,i);
		pushBack(head, i);
	}
	printList(head);
	deleteList(head, 10, p);
	cout << "删除的元素为" << p << endl;
	cout << "len = " << getLength(head) << endl;
	printList(head);
	insert(head,3,99);
	printList(head);
	head = reverse(head);
	printList(head);
	destroy(head);
	_CrtDumpMemoryLeaks();
	return 0;
}




