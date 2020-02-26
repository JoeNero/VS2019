#ifndef _LINK_LIST_H
#define _LINK_LIST_H

#include <iostream>

using namespace std;

typedef int Elemtype;

typedef struct Node
{
	Elemtype data;
	Node* next;
}LinkList;

bool InitList(LinkList*);			//��ʼ������
bool isEmpty(LinkList*);			//�п�
bool destroy(LinkList*);			//�ݻ�����
void clear(LinkList*);				//�������
int getLength(LinkList*);			//��ȡ������
void printList(LinkList*);			//��ӡ����

void revPrintList(LinkList*);		//�����ӡ����
void pushBack(LinkList*, Elemtype);	//β��
void BubbleSort(LinkList*);			//�����ð������
LinkList *getIntersectionNode(LinkList *headA, LinkList *headB);    //Ѱ������Ĺ����ڵ�
#endif // !_LINK_LIST_H
