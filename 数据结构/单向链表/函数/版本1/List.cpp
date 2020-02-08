#include "List.h"
#include <iostream>
#include "MyDebug.h"

using namespace std;

Node* createList()
{
	Node* head = new Node;                 //ͷ�ڵ�

	head->next = NULL;                            //�ʼ���һ���ڵ����ͷ�ڵ㣬
    
	return head;
}

Node* createList(Node* head, size_t n)
{
	Node* p = head;                          

	for (size_t i = 0; i < n; i++)
	{
		Node* pNew = new Node;                 //ͷ�ڵ�
		cout << "�����" << i + 1 << "����";
		cin >> pNew->data;

		pNew->next = NULL;					//�½ڵ����һ����ַΪ��              
		p->next = pNew;						//��ǰ�ڵ����һ����ַ��Ϊ�µĽڵ�
		p = pNew;
	}
	return head;
}

void printList(Node* head)
{
	if (nullptr == head)
	{
		cout << "��������" << endl;
		return;
	}
	else if (isEmpty(head))
	{
		cout << "��ӡ����Ϊ��" << endl;
		return;
	}
	else
	{
		Node* p = head;                 //��ָ��ָ��ͷ���
		while (p->next !=NULL )        //��ָ�����һ����ַ��Ϊ��ʱ��ѭ�����p��������
		{
			p = p->next;               //pָ��p����һ����ַ
			cout << p->data << " ";	
			
		}
		cout << endl;
	}
	
}

bool isEmpty(Node* head)
{
	if (NULL == head->next)
	{
		return true;            //�շ���    true
	}
	return false;
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

//���ҽڵ�
Node* searchPoint(Node* head, size_t n)
{
	Node* p = head;
	if (isEmpty(head))
	{
		cout << "����գ��޷����ҽڵ�" << endl;
		return NULL;
	}
	else if (n > getLength(head))
	{
		cout << "���ҽڵ��������ĳ���" << endl;
		return NULL;
	}
	else
	{
		for (size_t i = 0; i < n; i++)
		{
			p = p->next;
		}
		cout << "data = " << p->data << endl;
		return p;
	}
}

//��ָ��λ�ò���ڵ�
void insertPoint(Node* head, size_t n, int data)
{
	if ((n < 1) || (n > getLength(head)))
	{
		cout << "����ڵ�����" << endl;
		return;
	}
	else
	{
		Node* newNode = new Node;     //����һ��Node���ָ��newNode
		newNode->next = NULL;         //����newNode���������ָ����
		newNode->data = data;
		Node* p = head;               //����ָ��pָ��ͷ���
		size_t i = 1;
		while (n > i)                 //������ָ����λ��
		{
			p = p->next;
			i++;
		}
		newNode->next = p->next;    //���½ڵ���뵽ָ����λ��
		p->next = newNode;
	}
}

//ͷ��
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

//ͷ��
void pushFront(Node* head, int data)
{
	Node* newNode = new Node;           //�����½ڵ�ͷ
	newNode->data = data;               //�洢����
	Node* p = head;
	if (isEmpty(head))
	{
		head = newNode;                 //��ͷ�ڵ�Ϊ�յ�ʱ������newNodeΪ�µ�ͷ�ڵ�
	}
	newNode->next = p->next;
	p->next = newNode;
}

//βɾ
void popBack(Node* head)
{
	Node* p = head;          //����һ��ָ��ָ��ͷ���
	Node* ptemp = NULL;      //����һ��ռλ�ڵ�
	if (p->next == NULL)           //�ж������Ƿ�Ϊ��
	{
		cout << "�������" << endl;
		return;
	}
	else
	{
		while (p->next != NULL)   //ѭ����β����ǰһ��
		{
			ptemp = p;            //��ptempָ��β����ǰһ���ڵ�
			p = p->next;          //pָ�����һ���ڵ�
		}
		delete p;                //ɾ��β���ڵ�
		p = NULL;
		ptemp->next = NULL;
	}
}

//ͷɾ
void popFront(Node* head)
{
	Node* p = head;          //����һ��ָ��ָ��ͷ���
	Node* ptemp = NULL;      //����һ��ռλ�ڵ�
	if (p->next == NULL)           //�ж������Ƿ�Ϊ��
	{
		cout << "�������" << endl;
		return;
	}
	else
	{
		Node* ptemp = NULL;      //����һ��ռλ�ڵ�
		p = p->next;
		ptemp = p->next;
		delete p;                //ɾ��ͷ���ڵ�
		p = NULL;
		head->next = ptemp;
	}
}

//ɾ������ڵ�
void deletePoint(Node* head, size_t n)
{
	Node* ptemp = searchPoint(head,n);      //����һ��ռλ�ڵ�
	if (NULL == ptemp)
	{
		cout << "ɾ������" << endl;
		return;
	}
	else
	{
		if (head->next == ptemp)           //�ж��ǲ���ͷ�ڵ�,�����,ɾ��ͷ�ڵ�
		{
			popFront(head);
		}
		else
		{
			Node* p = head;          //����һ��ָ��ָ��ͷ���
			while (p->next != ptemp)	 //ѭ����ָ��λ�õ�ǰһ���ڵ�
			{
				p = p->next;          //pָ�����һ���ڵ�
			}
			p->next = ptemp->next;
			delete ptemp;                //ɾ��ָ���ڵ�ڵ�
			ptemp = NULL;
		}
	}
}

//�������
void clear(Node* head)
{
	if (head == NULL)
	{
		cout << "�Ѿ��ǿ������������" << endl;
		return;
	}
	Node* p = head->next;
	Node* ptemp = NULL;
	while (p)                    //��ͷ������һ���ڵ����ɾ���ڵ�
	{
		ptemp = p->next;
		delete p;
		p = ptemp;
	}
	head->next = NULL;                 //ͷ������һ���ڵ�ָ��NULL
}

//��������
void destroy(Node* head)								
{

	if (NULL == head)
	{
		cout << "�����" << endl;
		return;
	}
	while (head)
	{
		Node* p = head->next;
		delete head;
		head = p;
	}
}

//����ת
Node* reverse(Node* head)
{
	if ((head == nullptr)||(head->next == nullptr))
	{
		return head;
	}
	else
	{
		Node* pCurrent;		//��ǰ
		Node* pPrev = nullptr;		//
		Node* pNext;
		pCurrent = head->next;
		while (pCurrent != NULL)
		{
			pNext = pCurrent->next;
			if (pNext == NULL)
			{
				pCurrent->next = pPrev;
				head->next = pCurrent;
				return head;
			}
			pCurrent->next = pPrev;
			pPrev = pCurrent;
			pCurrent = pNext;
		}
		return head;
	}
}
