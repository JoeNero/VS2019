/*
创建者	:	XTT
功能	:	Sort算法

时间	:	2020/01/14
*/
#ifndef __M_SORT_H
#define __M_SORT_H

#pragma comment(lib,"m_sort.lib")

int m_findMax(int*, int);							//查找数组中的最大值		
int m_findMin(int*, int);							//查找数组中的最小值

void m_Bubble_sort(int*, int);						//冒泡排序
void m_Bubble_sort(int* a, int length, int mode);	//冒泡排序mode控制

void m_Selection_sort(int*, int);					//选择排序
void m_Selection_sort(int*, int, int);				//选择排序

void m_Quick_sort(int arr[], int low, int high);	//快速排序

int binaryfind(int* , int, int, int, int);			//二分法查找,需要升序排列后,且无法检测重复数据
													//查找数为尾部数据无法查询到

int m_Fibonacci(int ,int );							//斐波那契数列


void m_print(int*, int);			//打印数组

#endif // !__M_SORT_H

