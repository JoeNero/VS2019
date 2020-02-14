#include "LinkedList.h"

bool InitList(LinkList* head)
{
	head->next = nullptr;
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
	head->next = nullptr;
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

void revPrintList(LinkList* head)
{
	if ((head == nullptr)||(nullptr == head->next))
	{
		return;
	}
	head = head->next;
	revPrintList(head);
	cout << head->data << " ";	
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

//�����ð������
void BubbleSort(LinkList* head)
{
	LinkList* p = nullptr;
	size_t len = getLength(head);
	
	if (head == nullptr)
	{
		cout << "��������";
		return;
	}
	for (size_t i = 0; i < len; i++)
	{
		p = head->next;
		for (size_t j = 0; j < len - i;j++)
		{
			if (p->data  > p->next->data)
			{
				int temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
			}
			p = p->next;
		}
	}
}
