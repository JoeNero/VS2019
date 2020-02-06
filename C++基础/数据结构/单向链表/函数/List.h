#ifndef __LIST_H
#define __LIST_H
//One-way linked list
//��������
//clear()���������������ڴ�й©
#include <iostream>

struct Node
{
	int data;
	Node* next;
};

Node* createList();
Node* createList(Node* ,size_t);					//����������

void printList(Node*);								//��ӡ������

bool isEmpty(Node*);								//�����п�
size_t getLength(Node*);							//��ȡ������

Node* searchPoint(Node* ,size_t);					//��Ѱ�ڵ�
void insertPoint(Node* ,size_t, int);				//����ڵ�

void pushBack(Node* ,int);						    //β��
void pushFront(Node* ,int);							//ͷ��

void popBack(Node*);								//βɾ
void popFront(Node*);								//ͷɾ
void deletePoint(Node*,size_t);						//ɾ��ָ���Ľڵ�

void clear(Node*);									//�������

void destroy(Node*);								//��������

#endif // !__LIST_H

