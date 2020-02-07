#include "List.h"
#include <iostream>
#include "MyDebug.h"

using namespace std;

Node* createList()
{
	Node* head = new Node;                 //头节点

	head->next = NULL;                            //最开始最后一个节点就是头节点，
    
	return head;
}

Node* createList(Node* head, size_t n)
{
	Node* p = head;                          

	for (size_t i = 0; i < n; i++)
	{
		Node* pNew = new Node;                 //头节点
		cout << "输入第" << i + 1 << "数据";
		cin >> pNew->data;

		pNew->next = NULL;					//新节点的下一个地址为空              
		p->next = pNew;						//当前节点的下一个地址设为新的节点
		p = pNew;
	}
	return head;
}

void printList(Node* head)
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
		while (p->next !=NULL )        //当指针的下一个地址不为空时，循环输出p的数据域
		{
			p = p->next;               //p指向p的下一个地址
			cout << p->data << " ";	
			
		}
		cout << endl;
	}
	
}

bool isEmpty(Node* head)
{
	if (NULL == head->next)
	{
		return true;            //空返回    true
	}
	return false;
}

//获取链表长度
size_t getLength(Node* head)
{
	int count = 0;                  //定义count计数
	Node* p = head->next;           //定义p指向头结点
	while (p != NULL)                //当指针的下一个地址不为空时，count+1
	{
		count++;
		p = p->next;                //p指向p的下一个地址
	}
	delete p;
	return count;
}

//查找节点
Node* searchPoint(Node* head, size_t n)
{
	Node* p = head;
	if (isEmpty(head))
	{
		cout << "链表空，无法查找节点" << endl;
		return NULL;
	}
	else if (n > getLength(head))
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

//再指定位置插入节点
void insertPoint(Node* head, size_t n, int data)
{
	if ((n < 1) || (n > getLength(head)))
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
}

//头插
void pushBack(Node* head, int data)
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
}

//头插
void pushFront(Node* head, int data)
{
	Node* newNode = new Node;           //定义新节点头
	newNode->data = data;               //存储数据
	Node* p = head;
	if (isEmpty(head))
	{
		head = newNode;                 //当头节点为空的时候，设置newNode为新的头节点
	}
	newNode->next = p->next;
	p->next = newNode;
}

//尾删
void popBack(Node* head)
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
}

//头删
void popFront(Node* head)
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
}

//删除任意节点
void deletePoint(Node* head, size_t n)
{
	Node* ptemp = searchPoint(head,n);      //创建一个占位节点
	if (NULL == ptemp)
	{
		cout << "删除错误" << endl;
		return;
	}
	else
	{
		if (head->next == ptemp)           //判断是不是头节点,如果是,删除头节点
		{
			popFront(head);
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
		}
	}
}

//清空链表
void clear(Node* head)
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
	head->next = NULL;                 //头结点的下一个节点指向NULL
}

//销毁链表
void destroy(Node* head)								
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

//链表翻转
Node* reverse(Node* head)
{
	if ((head == nullptr)||(head->next == nullptr))
	{
		return head;
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
				return head;
			}
			pCurrent->next = pPrev;
			pPrev = pCurrent;
			pCurrent = pNext;
		}
		return head;
	}
}
