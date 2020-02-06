#ifndef __LIST_H
#define __LIST_H
//One-way linked list
//单向链表
//clear()和析构函数内有内存泄漏
#include <iostream>

struct Node
{
	int data;
	Node* next;
};

Node* createList();
Node* createList(Node* ,size_t);					//创建单链表

void printList(Node*);								//打印单链表

bool isEmpty(Node*);								//链表判空
size_t getLength(Node*);							//获取链表长度

Node* searchPoint(Node* ,size_t);					//搜寻节点
void insertPoint(Node* ,size_t, int);				//插入节点

void pushBack(Node* ,int);						    //尾插
void pushFront(Node* ,int);							//头插

void popBack(Node*);								//尾删
void popFront(Node*);								//头删
void deletePoint(Node*,size_t);						//删除指定的节点

void clear(Node*);									//清空链表

void destroy(Node*);								//销毁链表

#endif // !__LIST_H

