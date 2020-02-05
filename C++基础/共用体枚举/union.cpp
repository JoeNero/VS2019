/*
创建者	:	XTT
功能	:	共用体

时间	:	2020/01/07
*/         
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;


//共用体，共用同一个内存地址 
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

	//只有最后一个成员str的值打印才正确，因为3个成员都是引用同一个内存地址
	//对它们三个赋值，会导致互相的覆盖
	//第二个成员打印3.13，好像差不多正确，实际打印错误
	//double占8个字节，第三个char是占6个字符，所以并没有完全覆盖8个字节的double pi 
	printf("test.i: %d\n", test.i);
	printf("test.pi: %.2f\n", test.pi);
	printf("test.str: %s\n", test.str);

	return 0;
}

