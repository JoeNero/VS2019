/*
创建者	:	XTT
功能	:	拷贝和替换算法
			#include <algorithm>
			-------------------------------------------------------------
			copy		-- 容器内指定范围的元素拷贝到另一容器中
			replace		-- 将容器内指定范围的旧元素修改为新元素
			replace_if	-- 容器内指定范围满足条件的元素替换为新元素
			swap		-- 互换两个容器的元素(大小可以不一致)
			-------------------------------------------------------------
			目标容器需要提前开辟空间
			copy(iterator beg, iterator end, iterator dest);
			按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
			beg 开始迭代器
			end 结束迭代器
			dest 目标起始迭代器

			-------------------------------------------------------------
			replace(iterator beg, iterator end, oldvalue, newvalue);
			将区间内旧元素 替换成 新元素
			beg 开始迭代器
			end 结束迭代器
			oldvalue 旧元素
			newvalue 新元素

			-------------------------------------------------------------
			replace_if(iterator beg, iterator end, _pred, newvalue);
			按条件替换元素，满足条件的替换成指定元素
			beg 开始迭代器
			end 结束迭代器
			_pred 谓词
			newvalue 替换的新元素
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

class ReplaceGreater30
{
public:
	bool operator()(int val)
	{
		return val >= 30;
	}
};

void copyTest(vector<int>&);
void replaceTest(vector<int>&);
void swapTest(vector<int>&, vector<int>&);

int main()
{
	vector<int> v1;
	vector<int> v2;
	srand((unsigned)time(NULL));
	for (size_t i = 0; i < 10; i++)
	{
		int temp = rand() % 40 + 1;
		//int temp = rand() % 10 + 1;
		v1.push_back(temp);
	}
	for (size_t i = 0; i < 20; i++)
	{
		int temp = rand() % 40 + 1;
		//int temp = rand() % 10 + 1;
		v2.push_back(100 - temp);
	}
	
	for (auto&s:v1)
	{
		cout << s << " ";
	}
	cout << endl;
	//copyTest(v1);
	//replaceTest(v1);
	swapTest(v1,v2);
}

void copyTest(vector<int>& v)
{
	vector<int> vT;
	vT.resize(v.size());
	copy(v.begin(),v.end(),vT.begin());
	for_each(vT.begin(),vT.end(), print);
}

void replaceTest(vector<int>& v)
{
	cout << "替换前" << endl;
	for (auto& s : v)
	{
		cout << s << " ";
	}
	cout << endl;
	cout << "替换前" << endl;
	replace(v.begin(),v.end(),2,20);
	for (auto& s : v)
	{
		cout << s << " ";
	}
	cout << endl;
	cout << "条件_替换" << endl;
	replace_if(v.begin(), v.end(), ReplaceGreater30(), 1000);
	for (auto& s : v)
	{
		cout << s << " ";
	}
}
void swapTest(vector<int>& v1, vector<int>& v2)
{
	swap(v1, v2);
	cout << "v1 = " << endl;
	for (auto& s: v1)
	{
		cout << s << " ";
	}
	cout << endl << v1.size() << endl;
	cout << "v2 = " << endl;
	for (auto& s : v2)
	{
		cout << s << " ";
	}
	cout << endl << v2.size() << endl;
}