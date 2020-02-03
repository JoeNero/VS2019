/*
创建者	:	XTT
功能	:	array容器
			array是固定大小的序列容器，不能删除清空只能覆盖
			array存储固定大小的元素在连续的精确的序列中。

			operator[]		:Access element (public member function )
			front()			:返回头元素
			back()			:返回尾元素
			data			:获取指向数据的指针获取指向数据的指针
			at(index)		:访问index 的元素

			fill(element)	:填充元素
			max_size		:最大大小
			size			:大小
			swap			:交换长度必须相等


时间	:	2020/01/08
*/
#include <iostream>
#include <algorithm>
#include <array>
#include <ctime>

using namespace std;

bool cmp(int x1, int x2)
{
	return x1 > x2;
}
void test();

int main()
{
	test();
	system("pause");
	return 0;
}
/*
功能: 	- array容器
		@param
描述	:
示例	:
*/
void test()
{
	srand((unsigned)time(NULL));
	array<int, 6> a1{ 1,2,3 };
	array<int, 6> a2;				//事先申请不为空
	cout << "a1是否为空" << a1.empty() << endl;
	cout << "a2是否为空" << a2.empty() << endl;
	cout << "a1.size = " << a1.size() << endl;
	cout << "a2.size = " << a2.size() << endl;
	cout << "a1.max_size = " << a1.max_size() << endl;
	//容器a中的元素从前往后枚举出来
	for (auto& s : a1)
	{
		cout << s << ends;
	}
	cout << endl;
	cout << "a1.front =" << a1.front() << endl;
	cout << "a1.back = " << a1.back() << endl;
	cout << "a1.data =" << a1.data() << endl;

	cout << "&a1.at[0] = " << &a1.at(0) << endl;
	cout << "a1.at[0] = " << a1.at(0) << endl;

	for (size_t i = 0; i < 6; i++)
	{
		a2[i] = rand() % 100;
		cout << a2[i] << ' ';
	}
	a1.fill(1);
	for (auto& s : a1)
	{
		cout << s << ends;
	}
	cout << endl << "交换:" << endl;

	//交换的长度必须相等
	a1.swap(a2);
	cout << "a1:" << endl;
	for (auto& s : a1)
	{
		cout << s << ends;
	}
	cout << endl << "a2:" << endl;
	for (auto& s : a2)
	{
		cout << s << ends;
	}

	//排序
	sort(a1.begin(), a1.end());
	cout << endl << "a1升序后" << endl;
	for (auto& s : a1)
	{
		cout << s << ends;
	}

	sort(a1.begin(), a1.end(),cmp);
	cout << endl << "a1降序后" << endl;
	for (auto& s : a1)
	{
		cout << s << ends;
	}
}
