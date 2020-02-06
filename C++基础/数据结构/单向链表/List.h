#ifndef __LIST_H
#define __LIST_H
//One-way linked list
//��������
//clear()���������������ڴ�й©
#include <iostream>

struct Node
{
	int data;
	Node* next;
};

class mList
{
public:
	mList();
	~mList();

	Node* createList(size_t);					//����������
	void printList();							//��ӡ������

	bool isEmpty();								//�����п�
	size_t getLength();							//��ȡ������

	Node* searchPoint(size_t);					//��Ѱ�ڵ�
	void insertPoint(size_t, int);				//����ڵ�

	void pushBack(int);						    //β��
	void pushFront(int);						//ͷ��

	void popBack();								//βɾ
	void popFront();							//ͷɾ
	void deletePoint(size_t);					//ɾ��ָ���Ľڵ�

	void clear();								//�������

	//void* operator new(size_t size)
	//{
	//	void* p = malloc(size);
	//	return (p);
	//}
	//void operator delete(void* p)
	//{
	//	free(p);
	//}

private:
	size_t m_len = 0;		//Ĭ��������
	Node* head;				//ͷ�ڵ�

};



#endif // !__LIST_H

