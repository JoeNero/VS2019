/*
创建者	:	XTT
功能	:	stack类操作
			先进后出,只有一个出口,
			栈中只有顶端元素才可以被外界使用
			因此不允许有遍历行为
			栈中进入数据:--入栈(push)
			栈中弹出数据:--出栈(pop)

时间	:	2020/01/07
*/

#include <iostream>
#include <stack>

using namespace std;

void test01();

int main()
{

	test01();
	system("pause");
	return 0;
}

/*
功能: 	- stack类
		@param
		@param
		@param
描述	:
示例	:
*/
void test01()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);

	while (!s.empty())
	{
		//输出栈顶元素
		cout << "栈顶元素" << s.top() << endl;
		//弹出栈顶元素
		s.pop();
	}
	cout << "栈的大小为:" << s.size() << endl;
}
