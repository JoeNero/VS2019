/*
创建者	:	XTT
功能	:	常用算术生成算法
			#include <numeric>

			-------------------------------------------------------------
			accumulate		-- 计算容器元素累计总和
			fill			-- 向容器中添加元素
			-------------------------------------------------------------
			accumulate(iterator beg, iterator end, value);
			计算容器元素累计总和
			beg 开始迭代器
			end 结束迭代器
			value 起始值
			-------------------------------------------------------------
			fill(iterator beg, iterator end, value);
			向容器中填充元素
			beg 开始迭代器
			end 结束迭代器
			value 填充的值
			-------------------------------------------------------------
时间	:	2020/01/08
*/

#define CRTDBG_MAP_ALLOC  
#include <crtdbg.h> 
#include <iostream>
#include <numeric>
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
	vector<int> v;
	v.resize(20);
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	int sum = accumulate(v.begin(), v.end(), 0);
	cout << "sum =" << sum << endl;
	fill(v.begin(),v.end(),2);
	for (auto& s: v)
	{
		cout << s << ends;
	}
}