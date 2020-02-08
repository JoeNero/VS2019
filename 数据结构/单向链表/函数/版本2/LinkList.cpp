#include "Linklist.h"

using namespace std;

bool InitList(LinkList* head)
{
	head->next = NULL;
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
	head->next = NULL;
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

//获取线性表的某个元素，通过变量返回
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

//按值查找返回索引
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

//在任意位置插入数据
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

//头插
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

LinkList* reverse(LinkList* head)
{
	if ((head == nullptr) || (head->next == nullptr))
	{
		return head;
	}
	else
	{
		LinkList* pCurrent;		//当前
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

