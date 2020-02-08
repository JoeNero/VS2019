#ifndef __LINK_LIST_H
#define __LINK_LIST_H

#include <iostream>

typedef int Elemtype;

typedef struct Node
{
	Elemtype data;
	Node* next;
}LinkList;

bool InitList(LinkList*);	//��ʼ������
bool isEmpty(LinkList*);	//�п�
bool destroy(LinkList*);	//�ݻ�����
void clear(LinkList*);		//�������

int getLength(LinkList*);	//��ȡ����

bool getElem(LinkList*, int, Elemtype&);			//��ȡ���Ա��ĳ��Ԫ�أ�ͨ����������	

bool locateElem(LinkList*, Elemtype);				//��ֵ�����Ƿ�������ֵ
bool insert(LinkList*, int, Elemtype);				//ָ��λ�ò���ָ���ڵ�
bool deleteList(LinkList* , int, Elemtype&);		//ɾ��ĳ�ڵ�	
void pushFront(LinkList*, Elemtype);				//ͷ��
void pushBack(LinkList*, Elemtype);					//β��
void printList(LinkList*);							//��ӡ����
LinkList* reverse(LinkList*);						//��ת����


#endif // !__LINK_LIST_H