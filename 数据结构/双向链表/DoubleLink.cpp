#include "DoubleLink.h"
#include <iostream>

using namespace std;

//����˫������Ĭ��ֻ��ͷ�ڵ�� ָ�������������
Node* createList()
{
	Node* head = new Node;                 //ͷ�ڵ�
	Node* end;                             //β�ڵ�

	end = head;                            //�ʼ���һ���ڵ����ͷ�ڵ㣬

	end->next = NULL;                       //��������ָ��һ���µ�ַ
	head->last = NULL;                      //�����ʼ�Ľڵ�û����һ���ڵ�
	return head;
}

//����˫������
Node* createList(int n)
{
	Node* head = new Node;                 //ͷ�ڵ�
	Node* normal;                          //�����ڵ�
	Node* end;                             //β�ڵ�

	end = head;                            //�ʼ���һ���ڵ����ͷ�ڵ㣬

	for (int i = 0; i < n; i++)
	{
		normal = new Node;					//���½ڵ�����ռ�
		cout << "�����" << i + 1 << "����";
		cin >> normal->data;
		/* ���½ڵ�������ݣ�ע������ֻ������Ľڵ�������ݣ�head��������*/
		end->next = normal;                 //��end�������½ڵ�
		normal->last = end;                 //�½ڵ����һ���ڵ����end
		end = normal;                       //���һ���ڵ����½ڵ�
	}
	end->next = NULL;                       //��������ָ��һ���µ�ַ
	head->last = NULL;                      //�����ʼ�Ľڵ�û����һ���ڵ�
	return head;
}

//��ӡ����
void printList(Node* head)
{
	if (nullptr == head)
	{
		cout << "δ��������" << endl;
		return;
	}
	else if (head->next == NULL)
	{
		cout << "��ӡ������Ϊ��" << endl;
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

//�п�
bool isEmpty(Node* head)
{
	if (NULL == head->next)
	{
		return true;            //�շ���    true
	}
	return false;               //�ǿշ���  false
}

size_t getLength(Node* head)
{
	int count = 0;                  //����count����
	Node* p = head->next;           //����pָ��ͷ���
	while (p != NULL)                //��ָ�����һ����ַ��Ϊ��ʱ��count+1
	{
		count++;
		p = p->next;                //pָ��p����һ����ַ
	}
	return count;                   //����count������
}

//β��
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
		cout << "�����ѿգ��޷��Ƴ�";
		return;
	}
	else
	{
		//��bug û�и����ݻ������²���,�����굥�����ٻ�������
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
