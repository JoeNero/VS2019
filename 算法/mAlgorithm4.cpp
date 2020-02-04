/*
创建者	:	XTT
功能	:	常用集合算法
			#include <algorithm>
			-------------------------------------------------------------
			set_intersection // 求两个容器的交集
			set_union // 求两个容器的并集
			set_difference // 求两个容器的差集
			-------------------------------------------------------------
			set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
			求两个集合的交集
			注意:两个集合必须是有序序列
			beg1 容器1开始迭代器 
			end1 容器1结束迭代器 
			beg2 容器2开始迭代器 
			end2 容器2结束迭代器 
			dest 目标容器开始迭代器
			-------------------------------------------------------------
			set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
			求两个集合的并集
			注意:两个集合必须是有序序列
			beg1 容器1开始迭代器 
			end1 容器1结束迭代器 
			beg2 容器2开始迭代器 
			end2 容器2结束迭代器 
			dest 目标容器开始迭代器
			-------------------------------------------------------------
时间	:	2020/01/08
*/

#define CRTDBG_MAP_ALLOC  
#include <crtdbg.h> 
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

void print(int val)
{
	cout << val << " ";
}

class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

int main()
{
	vector<int> v1;
	vector<int> v2;
	vector<int> vT;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for (size_t i = 0; i < 5; i++)
	{
		v2.push_back(i);
	}

	cout << "v1:" << endl;
	for (auto& s : v1)
	{
		cout << s << ends;
	}
	cout << endl;

	cout << "v2:" << endl;
	for (auto& s : v2)
	{
		cout << s << ends;
	}
	cout << endl;

	//取两个容器里面较小的值给目标容器开辟空间
	//求交集
	cout << "求交集" << endl;
	vT.resize(min(v1.size(),v2.size()));
	set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),vT.begin());
	for (auto& s: vT)
	{
		cout << s << ends;
	}
	cout << endl;
	//求并集
	cout << "求并集" << endl;
	vT.resize(v1.size()+v2.size());
	vector<int>::iterator itEnd = 
	set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vT.begin());
	for_each(vT.begin(),itEnd,MyPrint());
	cout << endl;
}