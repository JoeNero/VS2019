/*
创建者	:	XTT
功能	:	vector扩容
			新增元素：Vector通过一个连续的数组存放元素，如果集合已满，
			在新增数据的时候，就要分配一块更大的内存，将原来的数据复制过来，
			释放之前的内存，在插入新增的元素；
			对vector的任何操作，一旦引起空间重新配置，指向原vector的所有迭代器就都失效了
			初始时刻vector的capacity为0，塞入第一个元素后capacity增加为1；
			不同的编译器实现的扩容方式不一样，VS2015中以1.5倍扩容，GCC以2倍扩容。

时间	:	2020/02/15
*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> v;
	cout << v.capacity() << endl;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
		system("pause");
		cout << "size:" << v.size() << endl;
		cout << "capacity:" << v.capacity() << endl;
	}
	return 0;
}