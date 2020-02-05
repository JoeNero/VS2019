/*
文件名 	:   main.cpp
创建者	:	XTT
功能	:	字符操作


时间	:	2020/01/10
*/
#define CRTDBG_MAP_ALLOC  
#include <iostream>
#include <string>
#include <crtdbg.h> 
#include <stdlib.h>
#include "m_str.h"
using namespace std;
 
void test1();
void test2();
void test3();

void test();

int main()
{
    test();
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}

void test()
{
//	test1();
	test2();
//	test3();
}

void test1()
{
	char p1[] =  "1239991" ;
	size_t len = strlen(p1);
	//cout << "len = " << len << endl;
	len += 1;
	char* p2 = new char[len];
	char* p3 = new char[len];
	m_strcpy(p2, p1);
	m_strcpy_len(p3,p1,len-1);

	cout << "p1=" << p1 << '\t' << "size=" << m_strlen(p1) << endl;
	cout << "p2=" << p2 << '\t' << "size=" << m_strlen(p2) << endl;
	cout << "p3=" << p3 << '\t' << "size=" << m_strlen(p3) << endl;

	m_reverse(p1);
	cout << "p1=" << p1 << '\t' << "size=" << m_strlen(p1) << endl;

	delete[] p2;
	delete[] p3;
}

void test2()
{
	char p1[] = "101";
	size_t len = strlen(p1);
	len += 1;
	char* p2 = new char[len];
	cout << "len= " << len << endl;
	len = len * sizeof(char);
	cout << "len = " << len << endl;
	m_memcpy(p2, p1,len);
	cout << "p1=" << p1 << '\t' << "size=" << m_strlen(p1) << endl;
	cout << "p2=" << p2 << '\t' << "size=" << m_strlen(p2) << endl;

	delete[] p2;
}

void test3()
{
	char p1[60] = {"121416189"};
	char p2[] = "A";
	m_strcat(p1,p2);
	char* i= m_strstr(p1,p2);
	char m_char1 = '4';
	char* i1 = m_strchr(p1, m_char1);
	char m_char = '1';
	unsigned int num = m_strchr_cout(p1, m_char);
	cout << "p1=" << p1 << '\t' << "size=" << m_strlen(p1) << endl;
	cout << "查找子串"<< p2 <<"返回值" << i << endl;
	cout << "查找字符"<< m_char1 << "返回值" << i1 << endl;
	cout << "查找字符"<< m_char << "出现的次数" << num<< endl;
}
