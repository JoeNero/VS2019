#include "ListPoint.h"
#include <iostream>

using namespace std;

//��ӡ�ڵ�
void printNode(Node* head)
{
	cout << ":"<< head << " ";
	cout << "next = " << head->next << " ";
	cout << "data = " << head->data << endl;
}

//��ӡ����
void printList(Node* head)
{
	if (nullptr == head)
	{
		cout << "��������" << endl;
		return;
	}
	else if (head == NULL)
	{
		cout << "��ӡ����Ϊ��" << endl;
		return;
	}
	else
	{
		Node* p = head;                 //��ָ��ָ��ͷ���
		while (p->next != NULL)        //��ָ�����һ����ַ��Ϊ��ʱ��ѭ�����p��������
		{
			p = p->next;               //pָ��p����һ����ַ
			cout << p->data << " ";
			//cout << p << " ";
			//cout << p->next << endl;
		}
		cout << endl;
	}
}

//ͷ��
void pushFront(Node* head, int data)
{
	Node* pNode = new Node();
	if (pNode == NULL)
	{
		return;
	}

	pNode->data = data;
	// ��û������
	if (head->next == nullptr)
	{
		head->next = pNode;
	}
	else
	{
		// ��ͷ��ʼ�������
		pNode->next = head->next;
		head->next = pNode;
	}
	return;
}

//β��
void pushBack(Node* head, int data)
{
	Node* pNew = new Node;          //����һ��Node���ָ��newNode
	pNew->next = NULL;              //����newNode���������ָ����
	pNew->data = data;
	Node* p = head;                 //����ָ��pָ��ͷ���
	if (head == NULL)
	{                               //��ͷ���Ϊ��ʱ������newNodeΪͷ���
		head = pNew;
	}
	else                            //ѭ��֪�����һ���ڵ㣬��newNode���������
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = pNew;
	}
}

//��ȡ������
size_t getLength(Node* head)
{
	int count = 0;                  //����count����
	Node* p = head->next;           //����pָ��ͷ���
	while (p != NULL)                //��ָ�����һ����ַ��Ϊ��ʱ��count+1
	{
		count++;
		p = p->next;                //pָ��p����һ����ַ
	}
	delete p;
	return count;
}

//������ķ�ת
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