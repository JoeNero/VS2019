#include <string>
//#include <utility>
#include <iostream>

using namespace std;

void test01()
{
	pair<string, int> p(string("Tom"), 20);

	cout << "����:" << p.first << "����:" << p.second << endl;

	pair<string, int> p2 = make_pair("jerry", 20);

	cout << "����:" << p2.first << "����:" << p2.second << endl;
}

int main()
{
	test01();
	system("pause");

	return 0;

}