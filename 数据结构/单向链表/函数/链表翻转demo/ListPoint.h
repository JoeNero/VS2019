#ifndef __LIST_POINT_H
#define __LIST_POINT_H

struct Node
{
	int data;
	Node* next;
	Node() :data(0), next(nullptr) {}
	Node(int _data, Node* _next)
	{
		this->data = _data;
		this->next = _next;
	}
};

void printNode(Node*);
void printList(Node*);

void pushFront(Node* head, int data);		//头插
void pushBack(Node* head, int data);		//尾插
size_t getLength(Node* head);				//获取链表长度

void reverse(Node*);						//链表翻转

#endif // !__LIST_POINT_	