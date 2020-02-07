#include "List.h"
#include <iostream>

using namespace std;

mList::mList()
{
	head = new Node;
	head->data = 0;			//��ʼ��ͷ�ڵ�
	head->next = NULL;		//ͷ�ڵ���һ������ΪNULL
}

mList::~mList()
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

//����һ��������
Node* mList::createList(size_t n)
{
	Node* ptemp = head;
	if (n < 0)
	{       //�������ֵ����ʱ�������쳣
		cout << "����Ľڵ��������" << endl;
		exit(EXIT_FAILURE);
	}
	for (size_t i = 0; i < n; i++)
	{        //��ֵһ��һ�����뵥������
		Node* pnew = new Node;
		cout << "�������" << i + 1 << "��ֵ: ";
		cin >> pnew->data;
		pnew->next = NULL;          //�½ڵ����һ����ַΪNULL
		ptemp->next = pnew;         //��ǰ������һ����ַ��Ϊ�½ڵ�
		ptemp = pnew;               //����ǰ�����Ϊ�½ڵ�
	}
	m_len = n;
	return head;
}

//��ӡ������������
void mList::printList()
{
	if (isEmpty())
	{
		cout << "����Ϊ�ձ�" << endl;
	}
	else
	{
		Node* p = head;                 //��ָ��ָ��ͷ���
		while (NULL != p->next)        //��ָ�����һ����ַ��Ϊ��ʱ��ѭ�����p��������
		{
			p = p->next;               //pָ��p����һ����ַ
			cout << p->data << " ";
		}
		cout << endl;
		//cout << "len = " << m_len << endl;
	}
}

//�п�
bool mList::isEmpty()
{
	if (NULL == head->next)
	{
		return true;            //�շ���    true
	}
	return false;               //�ǿշ���  false
}

//��ȡ������
size_t mList::getLength()
{
	int count = 0;                  //����count����
	Node* p = head->next;           //����pָ��ͷ���
	while (p != NULL)                //��ָ�����һ����ַ��Ϊ��ʱ��count+1
	{
		count++;
		p = p->next;                //pָ��p����һ����ַ
	}
	m_len = count;
	return count;                   //����count������
}

//��Ѱ�ڵ�
Node* mList::searchPoint(size_t n)
{
	Node* p = head;
	if (isEmpty())
	{
		cout << "����գ��޷����ҽڵ�" << endl;
		return NULL;
	}
	else if (n > m_len)
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
void mList::insertPoint(size_t n, int data)
{
	if ((n < 1) || (n > m_len))
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
	m_len++;
}

//β��
void mList::pushBack(int data)
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
	m_len++;
}

//ͷ��
void mList::pushFront(int data)
{
	Node* newNode = new Node;           //�����½ڵ�ͷ
	newNode->data = data;               //�洢����
	Node* p = head;
	if (isEmpty())
	{
		head = newNode;                 //��ͷ�ڵ�Ϊ�յ�ʱ������newNodeΪ�µ�ͷ�ڵ�
	}
	newNode->next = p->next;
	p->next = newNode;
	m_len++;
}

//βɾ
void mList::popBack()
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
	m_len--;
}

//ͷɾ
void mList::popFront()
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
	m_len--;
}

//ɾ��ָ��λ�õ�����
void mList::deletePoint(size_t n)
{
	Node* ptemp = searchPoint(n);      //����һ��ռλ�ڵ�
	if (NULL == ptemp)
	{
		cout << "ɾ������" << endl;
		return;
	}
	else
	{
		if (head->next == ptemp)           //�ж��ǲ���ͷ�ڵ�,�����,ɾ��ͷ�ڵ�
		{
			popFront();
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
			m_len--;
		}
	}
}

//�������,����ͷ�ڵ�
void mList::clear()
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
	m_len = 0;
	head->next = NULL;                 //ͷ������һ���ڵ�ָ��NULL
}

//��ת����
void mList::reverse()
{
	if ((head == nullptr) || (head->next == nullptr))
	{
		return;
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
			}
			pCurrent->next = pPrev;
			pPrev = pCurrent;
			pCurrent = pNext;
		}
	}
}



