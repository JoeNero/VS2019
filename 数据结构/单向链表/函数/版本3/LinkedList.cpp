#include "LinkedList.h"

bool InitList(LinkList* head)
{
	head->next = nullptr;
	return true;
}

//判空
bool isEmpty(LinkList* head)
{
	if (head->next)
	{
		return false;	//非空
	}
	else
	{
		return true;	//空
	}
}

//销毁链表,从头节点开始销毁
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

//清空链表，保留头结点
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

//求链表长度
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

//打印链表
void printList(LinkList* head)
{
	if (nullptr == head)
	{
		cout << "链表不存在" << endl;
		return;
	}
	else if (isEmpty(head))
	{
		cout << "打印链表为空" << endl;
		return;
	}
	else
	{
		Node* p = head;                 //另指针指向头结点
		while (p->next != NULL)        //当指针的下一个地址不为空时，循环输出p的数据域
		{
			p = p->next;               //p指向p的下一个地址
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

//尾插
void pushBack(LinkList* head, Elemtype data)
{
	LinkList* pNew = new LinkList;          //定义一个Node结点指针newNode
	pNew->next = NULL;              //定义newNode的数据域和指针域
	pNew->data = data;
	LinkList* p = head;                 //定义指针p指向头结点
	if (head == NULL)
	{                               //当头结点为空时，设置newNode为头结点
		head = pNew;
	}
	else                            //循环知道最后一个节点，将newNode放置在最后
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = pNew;
	}
}

//链表的冒泡排序
void BubbleSort(LinkList* head)
{
	LinkList* p = nullptr;
	size_t len = getLength(head);
	
	if (head == nullptr)
	{
		cout << "链表不存在";
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
