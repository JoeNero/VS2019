/*
������	:	XTT
����	:   �ļ���д����
            

ʱ��	:	2020/02/07
*/
#include <iostream>
#include <fstream>

using namespace std;

void test1();

ifstream in("����.txt");
ifstream in("����.txt");

int main()
{
    test1();
    return 0;
}

void test1()
{
    int a[10];

    if (!in.is_open())
    {
        cout << "δ��" << endl;
        return ;
    }
    for (int i = 0; i < 10; i++)
    {
        in >> a[i];
    }
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    ofstream out("����.txt");
    for (int i = 0; i < 10; i++)
    {
        out << a[i] << " ";
    }
    in.close();
    out.close();
    cin.get();
}