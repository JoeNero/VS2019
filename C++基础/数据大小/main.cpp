/*
    编译器会按照4补齐
    不管有多少虚函数，只有一个虚标指针
*/
#include <iostream>
using namespace std;

double division(int a, int b);
struct MyStruct
{
    int a:10;
    bool b;
    char c:5;
};
class MyClass
{
public:
    MyClass() {};
    virtual~MyClass() {};

    int a;
private:
};

class MyClass1:MyClass
{
public:
    MyClass1() {};
    ~MyClass1() {};
    int i2;
private:
    int i;
};
void test1();
void test2();
void test3();
void test();

int main()
{

    //test1();
    //test2();
    test3();
   //cout << sizeof(MyClass) << endl;
   //cout << sizeof(MyClass1) << endl;
    //   test();
    return 0;
}

void test1()
{
    cout <<"char:\t\t"          << sizeof(char)         << endl;

    cout <<"short int:\t"       << sizeof(short int)    << endl;
    cout << "int:\t\t"          << sizeof(int)          << endl;
//  cout << sizeof(long int)    << endl; 和int 一样
    cout << "long long int:\t"  << sizeof(long long int)<< endl;
    cout << "float:\t\t"        << sizeof(float)        << endl;
    cout << "double:\t\t"       << sizeof(double)       << endl;
}

void test2()
{
    cout << sizeof(MyStruct);
}

void test3()
{
    cout << sizeof(MyClass)  << endl;
    cout << sizeof(MyClass1) << endl;
}

void test()
{
    int x = 50;
    int y = 0;
    double z = 0;

    try {
        z = division(x, y);
        cout << z << endl;
    }catch (const char* msg) {
        cerr << msg << endl;
    }
}

double division(int a, int b)
{
    if (b == 0)
    {
        throw "Division by zero condition!";
    }
    return (a / b);
}