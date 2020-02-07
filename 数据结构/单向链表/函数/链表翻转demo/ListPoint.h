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

void pushFront(Node* head, int data);		//ͷ��
void pushBack(Node* head, int data);		//β��
size_t getLength(Node* head);				//��ȡ������

void reverse(Node*);						//����ת

#endif // !__LIST_POINT_	