/*
������	:	XTT
����	:	

ʱ��	:	2020/02/11
*/
#include <iostream>
#include <ctime>
#include <string>

using namespace std;
long Fibonacci(int n)
{
	if ( n <= 2)
	{
		return 1;
	}
	else
	{
		return (Fibonacci(n - 1) + Fibonacci(n - 2));
	}
}
int main()
{
	while (true)
	{
		cout << "����ڼ���:" << endl;
		int n;
		cin >> n;
		cout << endl;
		cout << "����"<< Fibonacci(n)<< endl;
	}
	return 0;
}
