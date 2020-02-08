/*
创建者	:	XTT
功能	:   线性表
            

时间	:	2020/02/07
*/
#include <iostream>
#include "LinearList.h"
using namespace std;

int main()
{
	try
	{
		LinearList<int> L(5);
		cout << "len = " << L.Length() << endl;
		cout << "IsEmpty = " << L.IsEmpty() << endl;
		L.Insert(0, 2).Insert(1, 6);
		cout << "Lits is" << L << endl;
		cout << "IsEmpty = " << L.IsEmpty() << endl;
		int z;
		L.Find(1,z);
		cout << "First element is" << z << endl;
		cout << "Length = " << L.Length() << endl;
		L.Delete(1,z);
		cout << "Deleted elements is" << z << endl;
		cout << "List is" << L << endl;
	}
	catch (...)
	{
		cerr << "An exception has occurred" << endl;
	}
    return 0;
}
