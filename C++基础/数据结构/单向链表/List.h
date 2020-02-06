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

class mList
{
public:
	mList();
	~mList();

	Node* createList(size_t);					//创建单链表
	void printList();							//打印单链表

	bool isEmpty();								//链表判空
	size_t getLength();							//获取链表长度

	Node* searchPoint(size_t);					//搜寻节点
	void insertPoint(size_t, int);				//插入节点

	void pushBack(int);						    //尾插
	void pushFront(int);						//头插

	void popBack();								//尾删
	void popFront();							//头删
	void deletePoint(size_t);					//删除指定的节点

	void clear();								//清空链表

	//void* operator new(size_t size)
	//{
	//	void* p = malloc(size);
	//	return (p);
	//}
	//void operator delete(void* p)
	//{
	//	free(p);
	//}

private:
	size_t m_len = 0;		//默认链表长度
	Node* head;				//头节点

};



#endif // !__LIST_H

