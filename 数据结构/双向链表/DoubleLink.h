#ifndef _DOUBLE_LINK_H
#define _DOUBLE_LINK_H

#include <iostream>
using namespace std;

struct Node
{
	int data;		//������
	Node* last = nullptr;		//��һ���ڵ�ָ����
	Node* next = nullptr;		//��һ���ڵ�ָ����
	Node() :data(0), last(nullptr), next(nullptr) {}
	Node(int _data, Node* _last, Node* _next)
	{
		this->data = _data;
		this->last = _last;
		this->next = _next;
	}
};

Node* createList();				//����˫������
Node* createList(int);			//����˫������

void printList(Node*);			//��ӡ˫������
bool isEmpty(Node*);			//�п�
size_t getLength(Node*);		//��ȡ������

void travelFront(Node*);		//�������
void travelBack(Node*);			//�������

void pushBack(Node*, int);		//β��
void insertPoint(Node*, int);	//����λ�ò�

void popBack(Node*);			//βɾ
void popFront(Node*);			//ͷɾ
void deletePoint(Node*, size_t);	//ɾ������ڵ�
void remove(Node*, int);				//ɾ���ض�����

Node* searchPoint(Node*, int);		//��ȡ�ڵ�
int front(Node*);				//��ȡͷ�ڵ�
int back(Node*);				//��ȡβ�ڵ�

void clear(Node*);				//�������	

void destroyList(Node*);		//��������


#endif // !_DOUBLE_LINK_H
