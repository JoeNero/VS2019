/*
������	:	XTT
����	:	Sort�㷨

ʱ��	:	2020/01/14
*/
#ifndef __M_SORT_H
#define __M_SORT_H

#pragma comment(lib,"m_sort.lib")

int m_findMax(int*, int);							//���������е����ֵ		
int m_findMin(int*, int);							//���������е���Сֵ

void m_Bubble_sort(int*, int);						//ð������
void m_Bubble_sort(int* a, int length, int mode);	//ð������mode����

void m_Selection_sort(int*, int);					//ѡ������
void m_Selection_sort(int*, int, int);				//ѡ������

void m_Quick_sort(int arr[], int low, int high);	//��������

int binaryfind(int* , int, int, int, int);			//���ַ�����,��Ҫ�������к�,���޷�����ظ�����
													//������Ϊβ�������޷���ѯ��

int m_Fibonacci(int ,int );							//쳲���������


void m_print(int*, int);			//��ӡ����

#endif // !__M_SORT_H

