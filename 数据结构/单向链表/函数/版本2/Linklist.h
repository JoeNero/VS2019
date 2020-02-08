#ifndef __LINK_LIST_H
#define __LINK_LIST_H

#include <iostream>

typedef int Elemtype;

typedef struct Node
{
	Elemtype data;
	Node* next;
}LinkList;

bool InitList(LinkList*);	//初始化链表
bool isEmpty(LinkList*);	//判空
bool destroy(LinkList*);	//摧毁链表
void clear(LinkList*);		//清空链表

int getLength(LinkList*);	//获取长度

bool getElem(LinkList*, int, Elemtype&);			//获取线性表的某个元素，通过变量返回	

bool locateElem(LinkList*, Elemtype);				//按值查找是否存在这个值
bool insert(LinkList*, int, Elemtype);				//指定位置插入指定节点
bool deleteList(LinkList* , int, Elemtype&);		//删除某节点	
void pushFront(LinkList*, Elemtype);				//头插
void pushBack(LinkList*, Elemtype);					//尾插
void printList(LinkList*);							//打印链表
LinkList* reverse(LinkList*);						//翻转链表


#endif // !__LINK_LIST_H