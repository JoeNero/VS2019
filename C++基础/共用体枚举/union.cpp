/*
������	:	XTT
����	:	������

ʱ��	:	2020/01/07
*/         
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;


//�����壬����ͬһ���ڴ��ַ 
union Test
{
	int i;
	double pi;
	char str[6];
};

int main(void)
{
	union Test test;

	test.i = 520;
	test.pi = 3.14;
	strcpy_s(test.str, "FishC");

	printf("add od test.i: %p\n", &test.i);
	printf("add od test.pi: %p\n", &test.pi);
	printf("add od test.str: %p\n", &test.str);

	//ֻ�����һ����Աstr��ֵ��ӡ����ȷ����Ϊ3����Ա��������ͬһ���ڴ��ַ
	//������������ֵ���ᵼ�»���ĸ���
	//�ڶ�����Ա��ӡ3.13����������ȷ��ʵ�ʴ�ӡ����
	//doubleռ8���ֽڣ�������char��ռ6���ַ������Բ�û����ȫ����8���ֽڵ�double pi 
	printf("test.i: %d\n", test.i);
	printf("test.pi: %.2f\n", test.pi);
	printf("test.str: %s\n", test.str);

	return 0;
}

