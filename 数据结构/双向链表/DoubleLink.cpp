#include "DoubleLink.h"
#include <iostream>

using namespace std;

//创建双向链表默认只有头节点的 指针域和数据领域
Node* createList()
{
	Node* head = new Node;                 //头节点
	Node* end;                             //尾节点

	end = head;                            //最开始最后一个节点就是头节点，

	end->next = NULL;                       //链表的最后指向一个新地址
	head->last = NULL;                      //链表最开始的节点没有上一个节点
	return head;
}

//创建双向链表
Node* createList(int n)
{
	Node* head = new Node;                 //头节点
	Node* normal;                          //其他节点
	Node* end;                             //尾节点

	end = head;                            //最开始最后一个节点就是头节点，

	for (int i = 0; i < n; i++)
	{
		normal = new Node;					//给新节点申请空间
		cout << "输入第" << i + 1 << "数据";
		cin >> normal->data;
		/* 往新节点存入数据，注意我们只给后面的节点存入数据，head不存数据*/
		end->next = normal;                 //往end后增添新节点
		normal->last = end;                 //新节点的上一个节点就是end
		end = normal;                       //最后一个节点变成新节点
	}
	end->next = NULL;                       //链表的最后指向一个新地址
	head->last = NULL;                      //链表最开始的节点没有上一个节点
	return head;
}

//打印链表
void printList(Node* head)
{
	if (nullptr == head)
	{
		cout << "未创建链表" << endl;
		return;
	}
	else if (head->next == NULL)
	{
		cout << "打印的链表为空" << endl;
		return;
	}
	else
	{
		Node* p = head;
		while ((p = p->next) != NULL)
		{
			cout << p->data << " ";
		}
		cout << endl;
	}
	
}

//判空
bool isEmpty(Node* head)
{
	if (NULL == head->next)
	{
		return true;            //空返回    true
	}
	return false;               //非空返回  false
}

size_t getLength(Node* head)
{
	int count = 0;                  //定义count计数
	Node* p = head->next;           //定义p指向头结点
	while (p != NULL)                //当指针的下一个地址不为空时，count+1
	{
		count++;
		p = p->next;                //p指向p的下一个地址
	}
	return count;                   //返回count的数据
}

//尾插
void pushBack(Node* head, int data)
{
	Node* t = head;
	if (NULL == head)
	{
		Node* n = new Node;
		n->data = data;
		n->last = NULL;
		n->next = NULL;
		head = n;
	}
	else
	{
		while (t->next != NULL)
		{
			t = t->next;
		}
		Node* n = new Node;
		t->next = n;
		n->last = t;
		n->data = data;
		n->next = NULL;
	}
}


void insertPoint(Node* head, int data)
{

}

void remove(Node* head, int data)
{
	Node* t = head;
	if (head == NULL)
	{
		cout << "链表已空，无法移除";
		return;
	}
	else
	{
		//有bug 没有该数据还会往下查找,现整完单链表再回来整理
		while (t->data != data)
		{
			t = t->next;
		}
		t->last->next = t->next;
		t->next->last = t->last;
		delete t;
	}
}

Node* searchPoint(Node* head, int data)
{
	Node* p = head;
	int found = 0;
	while (p != NULL)
	{
		if (p->data == data)
		{
			cout << "Found";
			found = 1;
			break;
		}
		p = p->next;
	}
	if (found == 0)
	{
		cout << data << "Not Found";
		return NULL;
	}
	return 0;
}
