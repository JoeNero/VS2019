/*
创建者	:	XTT
功能	:

时间	:	2020/01/14
*/
#define CRTDBG_MAP_ALLOC    
#include <iostream>    
#include <crtdbg.h>  
#include <ctime>
#include <vector>
#include "m_sort.h"

using namespace std;

void test1();
void test2();
void test3();
void test4();
void test5();

int main()
{
 //   test1();
 //   test2();
 //   test3();
 //   test4();
    test5();
    cout << "time = " << (double)(clock()) / CLOCKS_PER_SEC << "s" << endl;
    _CrtDumpMemoryLeaks();
    system("pause");
    return 0;
}

void test1()
{
    int* a = new int[5];
    srand((unsigned)time(NULL));
    for (int i = 0; i < 5; i++)
    {
        a[i] = rand() % 100;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
    cout << "最大值" << m_findMax(a, 5) << endl;
    cout << "最小值" << m_findMin(a, 5) << endl;
    m_Selection_sort(a, 5, 1);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << "\t";
    }
    delete[] a;
}

void test2()
{
    int* a = new int[5];
    srand((unsigned)time(NULL));
    for (int i = 0; i < 5; i++)
    {
        a[i] = rand() % 6;
    }
    m_print(a, 5);
    m_Selection_sort(a, 5, 1);
    m_print(a, 5);
    binaryfind(a, 5, 0, 5, 3);
}

void test3()
{
    //for (int i = 0; i < 10; i++)
    //{
    //    cout << m_Fibonacci(i, 0) << "\t";
    //}
    for (int i = 0; i < 10; i++)
    {
        cout << m_Fibonacci(i, 1) << "\t";
    }
}

void test4()
{
    int a[] = { 57, 68, 59, 52, 72, 28, 96, 33, 24 };
    int len = sizeof(a) / sizeof(int);
    cout << "len = " << len << endl;
    m_Quick_sort(a,0,len-1);
    m_print(a, len);
}

void test5()
{
    const int len = 55000;
    int* a = new int[len];
    srand((unsigned)time(NULL));
    for (int i = 0; i < len; i++)
    {
        a[i] = rand() % len;
    }
 //   m_Bubble_sort(a,len);
 //   m_Quick_sort(a,0, len-1);
    m_Selection_sort(a,len);
    m_print(a, len);
}