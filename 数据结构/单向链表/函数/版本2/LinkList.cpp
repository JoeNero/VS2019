#include "Linklist.h"

using namespace std;

bool InitList(LinkList* head)
{
	head->next = NULL;
	return true;
}

//�п�
bool isEmpty(LinkList* head)
{
	if (head->next)
	{
		return false;	//�ǿ�
	}
	else
	{
		return true;	//��
	}
}

//��������,��ͷ�ڵ㿪ʼ����
bool destroy(LinkList* head)
{
	LinkList* p;
	while (head)
	{
		p = head;
		head = head->next;
		delete p;
	}
	return true;
}

//�����������ͷ���
void clear(LinkList* head)
{
	LinkList* p, * q;
	p = head->next;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	head->next = NULL;
}

//��������
int getLength(LinkList* head)
{
	LinkList* p = head->next;
	int i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

//��ȡ���Ա��ĳ��Ԫ�أ�ͨ����������
bool getElem(LinkList* head, int i, Elemtype& elem)
{
	LinkList* p = head->next;
	int j = 0;
	while (p && (j < i))
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
	{
		return false;
	}
	else
	{
		elem = p->data;
		return true;
	}
}

//��ֵ���ҷ�������
bool locateElem(LinkList* head, Elemtype e)
{
	LinkList* p = head->next;
	int j = 1;
	while (p&&p->data!= e)
	{
		p = p->next;
		j++;
	}
	if (p)
	{
		return j;
	}
	else
	{
		return 0;
	}
}

//������λ�ò�������
bool insert(LinkList* head, int i,Elemtype e)
{
	LinkList* p = head;
	int j = 0;
	while (p&& (j<i-1))
	{
		p = p->next;
		++j;
	}
	if (!p||(j>i-1))
	{
		return false;
	}
	else
	{
		LinkList* pNew = new LinkList;
		pNew->data = e;
		pNew->next = p->next;
		p->next = pNew;
		return true;
	}
}

bool deleteList(LinkList* head,int i,Elemtype& e)
{
	LinkList* p = head;
	int j = 0;
	while (p->next&&(j<i-1))
	{
		p = p->next;
		++j;
	}
	if (!(p->next)||(j>i-1))
	{
		return false;
	}
	else
	{
		LinkList* q = p->next;
		p->next = q->next;
		e = q->data;
		delete q;
		return true;
	}
}

//ͷ��
void pushFront(LinkList* head,Elemtype data)
{
	LinkList* pNew = new LinkList;
	LinkList* p = head;
	pNew->data = data;
	if (head == NULL)
	{
		head = pNew;
	}
	else
	{
		pNew->next = p->next;
		p->next = pNew;
	}
}

//β��
void pushBack(LinkList* head, Elemtype data)
{
	LinkList* pNew = new LinkList;          //����һ��Node���ָ��newNode
	pNew->next = NULL;              //����newNode���������ָ����
	pNew->data = data;
	LinkList* p = head;                 //����ָ��pָ��ͷ���
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

//��ӡ����
void printList(LinkList* head)
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
		while (p->next != NULL)        //��ָ�����һ����ַ��Ϊ��ʱ��ѭ�����p��������
		{
			p = p->next;               //pָ��p����һ����ַ
			cout << p->data << " ";
		}
		cout << endl;
	}
}

LinkList* reverse(LinkList* head)
{
	if ((head == nullptr) || (head->next == nullptr))
	{
		return head;
	}
	else
	{
		LinkList* pCurrent;		//��ǰ
		LinkList* pPrev = nullptr;		//
		LinkList* pNext;
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

