/*
创建者	:	XTT
功能	:	

时间	:	2020/02/11
*/
#include <iostream>
#include <ctime>
#include <string>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkList* head = new LinkList;
	srand((unsigned)time(NULL));
	InitList(head);
	for (size_t i = 0; i < 13; i++)
	{
		int temp = rand() % 100 + 1;
		pushBack(head, temp);
	}
	printList(head);
	revPrintList(head);
	cout << endl;
	BubbleSort(head);
	printList(head);
	return 0;
}
