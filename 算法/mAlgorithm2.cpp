/*
创建者	:	XTT
功能	:	算法
			#include <algorithm>
			-------------------------------------------------------------
			常用排序算法
			sort			-- 对容器内元素进行排序
			random_shuffle  -- 洗牌 指定范围内的元素随机调整次序
			merge			-- 容器元素合并，并存储到另一容器中
			reverse			-- 反转指定范围的元素
			-------------------------------------------------------------
			sort(iterator beg, iterator end, _Pred);
			按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
			beg 开始迭代器
			end 结束迭代器
			_Pred 谓词
			-------------------------------------------------------------
			random_shuffle(iterator beg, iterator end);
			指定范围内的元素随机调整次序
			beg 开始迭代器
			end 结束迭代器
			-------------------------------------------------------------
			merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
			容器元素合并，并存储到另一容器中

			!!!注意: 两个容器必须是有序的,都是升序或者降序

			beg1 容器1开始迭代器 // end1 容器1结束迭代器 // beg2 容器2开始迭代器 // end2 容器2结束迭代器 //
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

void sortTest(vector<int>&);
void randomShuffle(vector<int>&);
void mergeTest(vector<int>&, vector<int>&);

int main()
{
	vector<int> v;
	srand((unsigned)time(NULL));
	for (size_t i = 0; i < 10; i++)
	{
		int temp = rand() % 40 + 1;
		v.push_back(temp);
	}

	vector<int> v1;
	for (size_t i = 0; i < 10; i++)
	{
		int temp = rand() % 40 + 1;
		v1.push_back(temp);
	}

	//sortTest(v);
	//randomShuffle(v);
	mergeTest(v, v1);
}

void sortTest(vector<int>& v)
{
	//默认升序
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), print);
	cout << endl;
	//降序
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), print);
	cout << endl;
}

void randomShuffle(vector<int>& v)
{
	//默认升序
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), print);
	cout << endl;
	//打乱顺序
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), print);
	cout << endl;
}

void mergeTest(vector<int>& v1, vector<int>& v2)
{
	//默认升序
	sort(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), print);
	cout << endl;

	//默认升序
	sort(v2.begin(), v2.end());
	for_each(v2.begin(), v2.end(), print);
	cout << endl;
	vector<int> v3;
	v3.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for (auto& v : v3)
	{
		cout << v << " ";
	}
	cout << endl;
	reverse(v3.begin(),v3.end());
	for (auto& v : v3)
	{
		cout << v << " ";
	}
	cout << endl;
}