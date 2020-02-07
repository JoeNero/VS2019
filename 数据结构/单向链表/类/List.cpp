#include "List.h"
#include <iostream>

using namespace std;

mList::mList()
{
	head = new Node;
	head->data = 0;			//初始化头节点
	head->next = NULL;		//头节点下一个定义为NULL
}

mList::~mList()
{
	if (NULL == head)
	{
		cout << "链表空" << endl;
		return;
	}
	while (head)
	{
		Node* p = head->next;
		delete head;
		head = p;
	}
}

//创建一个单链表
Node* mList::createList(size_t n)
{
	Node* ptemp = head;
	if (n < 0)
	{       //当输入的值有误时，处理异常
		cout << "输入的节点个数有误" << endl;
		exit(EXIT_FAILURE);
	}
	for (size_t i = 0; i < n; i++)
	{        //将值一个一个插入单链表中
		Node* pnew = new Node;
		cout << "请输入第" << i + 1 << "个值: ";
		cin >> pnew->data;
		pnew->next = NULL;          //新节点的下一个地址为NULL
		ptemp->next = pnew;         //当前结点的下一个地址设为新节点
		ptemp = pnew;               //将当前结点设为新节点
	}
	m_len = n;
	return head;
}

//打印单向链表数据
void mList::printList()
{
	if (isEmpty())
	{
		cout << "链表为空表" << endl;
	}
	else
	{
		Node* p = head;                 //另指针指向头结点
		while (NULL != p->next)        //当指针的下一个地址不为空时，循环输出p的数据域
		{
			p = p->next;               //p指向p的下一个地址
			cout << p->data << " ";
		}
		cout << endl;
		//cout << "len = " << m_len << endl;
	}
}

//判空
bool mList::isEmpty()
{
	if (NULL == head->next)
	{
		return true;            //空返回    true
	}
	return false;               //非空返回  false
}

//获取链表长度
size_t mList::getLength()
{
	int count = 0;                  //定义count计数
	Node* p = head->next;           //定义p指向头结点
	while (p != NULL)                //当指针的下一个地址不为空时，count+1
	{
		count++;
		p = p->next;                //p指向p的下一个地址
	}
	m_len = count;
	return count;                   //返回count的数据
}

//搜寻节点
Node* mList::searchPoint(size_t n)
{
	Node* p = head;
	if (isEmpty())
	{
		cout << "链表空，无法查找节点" << endl;
		return NULL;
	}
	else if (n > m_len)
	{
		cout << "查找节点大于链表的长度" << endl;
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

//在指定位置插入节点
void mList::insertPoint(size_t n, int data)
{
	if ((n < 1) || (n > m_len))
	{
		cout << "插入节点有误" << endl;
		return;
	}
	else
	{
		Node* newNode = new Node;     //定义一个Node结点指针newNode
		newNode->next = NULL;         //定义newNode的数据域和指针域
		newNode->data = data;
		Node* p = head;               //定义指针p指向头结点
		size_t i = 1;
		while (n > i)                 //遍历到指定的位置
		{
			p = p->next;
			i++;
		}
		newNode->next = p->next;    //将新节点插入到指定的位置
		p->next = newNode;
	}
	m_len++;
}

//尾插
void mList::pushBack(int data)
{
	Node* pNew = new Node;          //定义一个Node结点指针newNode
	pNew->next = NULL;              //定义newNode的数据域和指针域
	pNew->data = data;
	Node* p = head;                 //定义指针p指向头结点
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
	m_len++;
}

//头插
void mList::pushFront(int data)
{
	Node* newNode = new Node;           //定义新节点头
	newNode->data = data;               //存储数据
	Node* p = head;
	if (isEmpty())
	{
		head = newNode;                 //当头节点为空的时候，设置newNode为新的头节点
	}
	newNode->next = p->next;
	p->next = newNode;
	m_len++;
}

//尾删
void mList::popBack()
{
	Node* p = head;          //创建一个指针指向头结点
	Node* ptemp = NULL;      //创建一个占位节点
	if (p->next == NULL)           //判断链表是否为空
	{
		cout << "单链表空" << endl;
		return;
	}
	else
	{
		while (p->next != NULL)   //循环到尾部的前一个
		{
			ptemp = p;            //将ptemp指向尾部的前一个节点
			p = p->next;          //p指向最后一个节点
		}
		delete p;                //删除尾部节点
		p = NULL;
		ptemp->next = NULL;
	}
	m_len--;
}

//头删
void mList::popFront()
{
	Node* p = head;          //创建一个指针指向头结点
	Node* ptemp = NULL;      //创建一个占位节点
	if (p->next == NULL)           //判断链表是否为空
	{
		cout << "单链表空" << endl;
		return;
	}
	else
	{
		Node* ptemp = NULL;      //创建一个占位节点
		p = p->next;
		ptemp = p->next;
		delete p;                //删除头部节点
		p = NULL;
		head->next = ptemp;
	}
	m_len--;
}

//删除指定位置的数据
void mList::deletePoint(size_t n)
{
	Node* ptemp = searchPoint(n);      //创建一个占位节点
	if (NULL == ptemp)
	{
		cout << "删除错误" << endl;
		return;
	}
	else
	{
		if (head->next == ptemp)           //判断是不是头节点,如果是,删除头节点
		{
			popFront();
		}
		else
		{
			Node* p = head;          //创建一个指针指向头结点
			while (p->next != ptemp)	 //循环到指定位置的前一个节点
			{
				p = p->next;          //p指向最后一个节点
			}
			p->next = ptemp->next;
			delete ptemp;                //删除指定节点节点
			ptemp = NULL;
			m_len--;
		}
	}
}

//清空链表,保留头节点
void mList::clear()
{
	if (head == NULL)
	{
		cout << "已经是空链表，不用清空" << endl;
		return;
	}
	Node* p = head->next;
	Node* ptemp = NULL;
	while (p)                    //在头结点的下一个节点逐个删除节点
	{
		ptemp = p->next;
		delete p;
		p = ptemp;	
	}
	m_len = 0;
	head->next = NULL;                 //头结点的下一个节点指向NULL
}

//翻转链表
void mList::reverse()
{
	if ((head == nullptr) || (head->next == nullptr))
	{
		return;
	}
	else
	{
		Node* pCurrent;		//当前
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



