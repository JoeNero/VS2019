#ifndef _DOUBLE_LINK_H
#define _DOUBLE_LINK_H

#include <iostream>
using namespace std;

struct Node
{
	int data;		//数据域
	Node* last = nullptr;		//上一个节点指针域
	Node* next = nullptr;		//下一个节点指针域
	Node() :data(0), last(nullptr), next(nullptr) {}
	Node(int _data, Node* _last, Node* _next)
	{
		this->data = _data;
		this->last = _last;
		this->next = _next;
	}
};

Node* createList();				//创建双向链表
Node* createList(int);			//创建双向链表

void printList(Node*);			//打印双向链表
bool isEmpty(Node*);			//判空
size_t getLength(Node*);		//获取链表长度

void travelFront(Node*);		//正向遍历
void travelBack(Node*);			//反向遍历

void pushBack(Node*, int);		//尾插
void insertPoint(Node*, int);	//任意位置插

void popBack(Node*);			//尾删
void popFront(Node*);			//头删
void deletePoint(Node*, size_t);	//删除任意节点
void remove(Node*, int);				//删除特定数据

Node* searchPoint(Node*, int);		//获取节点
int front(Node*);				//获取头节点
int back(Node*);				//获取尾节点

void clear(Node*);				//清空链表	

void destroyList(Node*);		//销毁链表


#endif // !_DOUBLE_LINK_H
