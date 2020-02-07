/*
创建者	:	XTT
功能	:	Sort算法

时间	:	2020/01/14
*/
#include "m_sort.h"
#include <iostream>

using namespace std;

/*
功能: 	- 查找数组中最大值
		@int* a		:	目标数组
		@int length	:	数组长度
		@param
		@return		:	最大值
描述	:
示例	:	m_findMax(a, 5);
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
	//cout << "最大值" << max << endl;
	//cout << "索引"   << MaxIndex << endl;
	//return MaxIndex;
	return max;
}

/*
功能: 	- 查找数组中最小值
		@int* a		:	目标数组
		@int length	:	数组长度
		@param
		@return		:	最小值
描述	:
示例	:	m_findMin(a, 5);
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
	//cout << "最小值" << min << endl;
	//cout << "索引" << MinIndex << endl;
	//return MinIndex;
	return min;
}

/*
功能: 	- 冒泡排序:默认降序
		@int* a		:	目标数组
		@int length	:	数组长度
		@param
		@return		:	无
描述	:
示例	:	m_Bubble_sort(a, 5);
*/
void m_Bubble_sort(int* a, int length)		
{
	int temp;
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (a[j] < a[j + 1])		// >:升序
										// <:降序
			{
				//交换
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

/*
功能: 	- 冒泡排序:
		@int* a		:	目标数组
		@int length	:	数组长度
		@int mode	:	0 :降序
						1 :升序
		@return		:	无
描述	:
示例	:	m_Bubble_sort(a, 5, 1);
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
功能: 	- 选择排序:默认升序
		@int* a		:	目标数组
		@int length	:	数组长度
		@param
		@return		:	无
描述	:
示例	:	m_Selection_sort(a, 5);
*/
void m_Selection_sort(int* a, int length)
{
	int temp;
	int min = 0; 				//假设最小值是数组的第一个元素
	int minIndex = 0;			//最小值的初始下标为0
	for (int i = 0; i < length - 1; i++)
	{
		min = a[i];			//假设第i个元素是最小值
		minIndex = i;
		for (int j = i + 1; j < length; j++)
		{
			if (a[j] < min)			
			{                          
				min = a[j];
				minIndex = j;
			}
		}
		//交换
		if (minIndex > i)
		{
			temp = a[minIndex];
			a[minIndex] = a[i];
			a[i] = temp;
		}
	}
}

/*
功能: 	- 选择排序:
		@int* a		:	目标数组
		@int length	:	数组长度
		@int mode	:	0:降序
						1:升序
		@return		:	无
描述	:
示例	:	m_Selection_sort(a, 5);
*/
void m_Selection_sort(int* a, int length, int mode)
{
	int temp;
	int min = 0; 				//假设最小值是数组的第一个元素
	int minIndex = 0;			//最小值的初始下标为0
	for (int i = 0; i < length - 1; i++)
	{
		min = a[i];			//假设第i个元素是最小值
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
		//交换
		if (minIndex > i)
		{
			temp = a[minIndex];
			a[minIndex] = a[i];
			a[i] = temp;
		}
	}
}

/*
功能: 	- 二分法查找
		@unsigned int* a	: 源数组
		@int length		    : 数组长度
		@int low			: 起始位置
		@int high			: 结束位置
		@int x				: 查找数字
描述	:	binaryfind(a, 5, 0, 5, 3);
*/
int binaryfind(int* a, int length, int low, int high, int x)
{
	int* temp = a;
	int min = low;
	int max = high;
	int mid = (min + max) / 2;
	//若区间大小已经为0，则不存在查找的空间中
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
		cout << "查找到的数值为" << x << endl;
		cout << "为数组第" << mid << endl;
	}
	return mid;
}

/*
功能: 	- 斐波那契
		@ int n		: 数列序号
		@ int mode	:	0 :递归
						1 :分治法

描述	:	
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
功能: 	- 快速排序
		@ int arr[]	: 目标数组
		@ int low	:	
		@ int high	:			

描述	:
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
//交换key值
	int temp = a[left];
	a[left] = a[j];
	a[j] = temp;

	m_Quick_sort(a,left,j-1);
	m_Quick_sort(a,j+1,right);
}