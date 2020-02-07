#include "ListPoint.h"
#include <iostream>

using namespace std;

//打印节点
void printNode(Node* head)
{
	cout << ":"<< head << " ";
	cout << "next = " << head->next << " ";
	cout << "data = " << head->data << endl;
}

//打印链表
void printList(Node* head)
{
	if (nullptr == head)
	{
		cout << "链表不存在" << endl;
		return;
	}
	else if (head == NULL)
	{
		cout << "打印链表为空" << endl;
		return;
	}
	else
	{
		Node* p = head;                 //另指针指向头结点
		while (p->next != NULL)        //当指针的下一个地址不为空时，循环输出p的数据域
		{
			p = p->next;               //p指向p的下一个地址
			cout << p->data << " ";
			//cout << p << " ";
			//cout << p->next << endl;
		}
		cout << endl;
	}
}

//头插
void pushFront(Node* head, int data)
{
	Node* pNode = new Node();
	if (pNode == NULL)
	{
		return;
	}

	pNode->data = data;
	// 若没有数据
	if (head->next == nullptr)
	{
		head->next = pNode;
	}
	else
	{
		// 从头开始往后插入
		pNode->next = head->next;
		head->next = pNode;
	}
	return;
}

//尾插
void pushBack(Node* head, int data)
{
	Node* pNew = new Node;          //定义一个Node结点指针newNode
	pNew->next = NULL;              //定义newNode的数据域和指针域
	pNew->data = data;
	Node* p = head;                 //定义指针p指向头结点
	if (head == NULL)
	{                               //当头结点为空时，设置newNode为头结点
		head = pNew;
	}
	else                            //循环知道最后一个节点，将newNode放置在最后
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = pNew;
	}
}

//获取链表长度
size_t getLength(Node* head)
{
	int count = 0;                  //定义count计数
	Node* p = head->next;           //定义p指向头结点
	while (p != NULL)                //当指针的下一个地址不为空时，count+1
	{
		count++;
		p = p->next;                //p指向p的下一个地址
	}
	delete p;
	return count;
}

//单链表的翻转
void reverse(Node* head)
{
	if ((head->next == nullptr )||(head->next->next == nullptr))
	{
		return;
	}
	else
	{
		Node* pCur = head->next;
		Node* pNext = pCur->next;
		Node* pre = nullptr;
		while (pNext)
		{
			pCur->next = pre;
			pre = pCur;
			pCur = pNext;
			pNext = pCur->next;
		}
		pCur->next = pre;
		head->next = pCur;
		return;
	}
}