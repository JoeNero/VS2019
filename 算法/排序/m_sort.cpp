/*
������	:	XTT
����	:	Sort�㷨

ʱ��	:	2020/01/14
*/
#include "m_sort.h"
#include <iostream>

using namespace std;

/*
����: 	- �������������ֵ
		@int* a		:	Ŀ������
		@int length	:	���鳤��
		@param
		@return		:	���ֵ
����	:
ʾ��	:	m_findMax(a, 5);
*/
int m_findMax(int* a,int length)					
{
	int* temp = a;
	int MaxIndex = 0;
	int max = temp[0];
	for (int i = 1; i < length; i++)
	{
		if (temp[i] > max)
		{
			max = temp[i];
			MaxIndex = i;
		}
	}
	//cout << "���ֵ" << max << endl;
	//cout << "����"   << MaxIndex << endl;
	//return MaxIndex;
	return max;
}

/*
����: 	- ������������Сֵ
		@int* a		:	Ŀ������
		@int length	:	���鳤��
		@param
		@return		:	��Сֵ
����	:
ʾ��	:	m_findMin(a, 5);
*/
int m_findMin(int* a,int length)			
{
	int* temp = a;
	int MinIndex = 0;
	int min = temp[0];
	for (int i = 1; i < length; i++)
	{
		if (temp[i] < min)
		{
			min = temp[i];
			MinIndex = i;
		}
	}
	//cout << "��Сֵ" << min << endl;
	//cout << "����" << MinIndex << endl;
	//return MinIndex;
	return min;
}

/*
����: 	- ð������:Ĭ�Ͻ���
		@int* a		:	Ŀ������
		@int length	:	���鳤��
		@param
		@return		:	��
����	:
ʾ��	:	m_Bubble_sort(a, 5);
*/
void m_Bubble_sort(int* a, int length)		
{
	int temp;
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (a[j] < a[j + 1])		// >:����
										// <:����
			{
				//����
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

/*
����: 	- ð������:
		@int* a		:	Ŀ������
		@int length	:	���鳤��
		@int mode	:	0 :����
						1 :����
		@return		:	��
����	:
ʾ��	:	m_Bubble_sort(a, 5, 1);
*/
void m_Bubble_sort(int* a, int length, int mode)
{
	int temp;
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			switch (mode)
			{
			case 0:
				if (a[j] < a[j + 1])										
				{
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
				break;
			case 1:
				if (a[j] > a[j + 1])		
				{
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
				break;
			default:
				cout << "mode_error" << endl;
				return;
			}

		}
	}
}

/*
����: 	- ѡ������:Ĭ������
		@int* a		:	Ŀ������
		@int length	:	���鳤��
		@param
		@return		:	��
����	:
ʾ��	:	m_Selection_sort(a, 5);
*/
void m_Selection_sort(int* a, int length)
{
	int temp;
	int min = 0; 				//������Сֵ������ĵ�һ��Ԫ��
	int minIndex = 0;			//��Сֵ�ĳ�ʼ�±�Ϊ0
	for (int i = 0; i < length - 1; i++)
	{
		min = a[i];			//�����i��Ԫ������Сֵ
		minIndex = i;
		for (int j = i + 1; j < length; j++)
		{
			if (a[j] < min)			
			{                          
				min = a[j];
				minIndex = j;
			}
		}
		//����
		if (minIndex > i)
		{
			temp = a[minIndex];
			a[minIndex] = a[i];
			a[i] = temp;
		}
	}
}

/*
����: 	- ѡ������:
		@int* a		:	Ŀ������
		@int length	:	���鳤��
		@int mode	:	0:����
						1:����
		@return		:	��
����	:
ʾ��	:	m_Selection_sort(a, 5);
*/
void m_Selection_sort(int* a, int length, int mode)
{
	int temp;
	int min = 0; 				//������Сֵ������ĵ�һ��Ԫ��
	int minIndex = 0;			//��Сֵ�ĳ�ʼ�±�Ϊ0
	for (int i = 0; i < length - 1; i++)
	{
		min = a[i];			//�����i��Ԫ������Сֵ
		minIndex = i;
		for (int j = i + 1; j < length; j++)
		{
			switch (mode)
			{
			case 0:
				if (a[j] > min)
				{
					min = a[j];
					minIndex = j;
				}
				break;
			case 1:
				if (a[j] < min)
				{
					min = a[j];
					minIndex = j;
				}
				break;
			default:
				cout << "mode_error" << endl;
				return;
			}
		}
		//����
		if (minIndex > i)
		{
			temp = a[minIndex];
			a[minIndex] = a[i];
			a[i] = temp;
		}
	}
}

/*
����: 	- ���ַ�����
		@unsigned int* a	: Դ����
		@int length		    : ���鳤��
		@int low			: ��ʼλ��
		@int high			: ����λ��
		@int x				: ��������
����	:	binaryfind(a, 5, 0, 5, 3);
*/
int binaryfind(int* a, int length, int low, int high, int x)
{
	int* temp = a;
	int min = low;
	int max = high;
	int mid = (min + max) / 2;
	//�������С�Ѿ�Ϊ0���򲻴��ڲ��ҵĿռ���
	if (mid == 0)
	{
		cout << "error" << endl;
		return NULL;
	}
	if (temp[mid] > x)
	{
		min = min;
		max = max - (max + min) / 2;
		if (max < 0)
		{
			cout << "error" << endl;
			return NULL;
		}
		binaryfind(temp, mid, min, max, x);
	}
	else if (temp[mid] < x)
	{
		min = min + (max + min) / 2;
		max = max;
		if (min > max)
		{
			cout << "error" << endl;
			return NULL;
		}
		binaryfind(temp, mid, min, max, x);
	}
	else if (x == temp[mid])
	{
		cout << "���ҵ�����ֵΪ" << x << endl;
		cout << "Ϊ�����" << mid << endl;
	}
	return mid;
}

/*
����: 	- 쳲�����
		@ int n		: �������
		@ int mode	:	0 :�ݹ�
						1 :���η�

����	:	
*/
int m_Fibonacci(int n, int mode)
{
	if (n == 0)
		return 0;
	if (n <= 2)
		return 1;
	else
	{
		switch (mode)
		{
		case 0:
			{
				return (m_Fibonacci(n - 1, 0) + m_Fibonacci(n - 2, 0));
			}
			
		case 1:
			{
				int first = 0;
				int second = 1;
				while (0 < n--)
				{
					second += first;
					first = second - first;
				}
				return (first + second);
			}
		default:
			{
				cout << "" << endl;
				return NULL;
			}
		}
	}
	
}

void m_print(int* a, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

/*
����: 	- ��������
		@ int arr[]	: Ŀ������
		@ int low	:	
		@ int high	:			

����	:
*/
void m_Quick_sort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int i = left;
	int key = a[right];
	int j = right+1;

	while (true)
	{
		while (a[++i] < key)
		{
			if (i == right)
			{
				break;
			}
		}
		while (a[--j] > key)
		{
			if (j == left)
			{
				break;
			}
		}
		if (i >= j)break;
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
//����keyֵ
	int temp = a[left];
	a[left] = a[j];
	a[j] = temp;

	m_Quick_sort(a,left,j-1);
	m_Quick_sort(a,j+1,right);
}