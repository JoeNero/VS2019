#ifndef _LINK_LIST_H
#define _LINK_LIST_H

#include <iostream>

using namespace std;

typedef int Elemtype;

typedef struct Node
{
	Elemtype data;
	Node* next;
}LinkList;

bool InitList(LinkList*);			//初始化链表
bool isEmpty(LinkList*);			//判空
bool destroy(LinkList*);			//摧毁链表
void clear(LinkList*);				//清空链表
int getLength(LinkList*);			//获取链表长度
void printList(LinkList*);			//打印链表

void revPrintList(LinkList*);		//逆序打印链表
void pushBack(LinkList*, Elemtype);	//尾插
void BubbleSort(LinkList*);			//链表的冒泡排序
LinkList *getIntersectionNode(LinkList *headA, LinkList *headB);    //寻找链表的公共节点
#endif // !_LINK_LIST_H
