/*
创建者	:	XTT
功能	:	queue容器
			先进先出,两个出口
			队列容器允许从一端新增元素，从另一端移除元素
			队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为
			队列中进数据称为 --- 入队 push
			队列中出数据称为 --- 出队 pop

时间	:	2020/01/08
*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	~Person() {};

	string m_Name;
	int m_Age;
};


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
	//创建
	queue<Person> q;

	//准备数据
	Person p1("唐僧", 30);
	Person p2("孙悟空", 1000);
	Person p3("猪八戒", 900);
	Person p4("沙僧", 800);

	//向队列中添加元素 队列操作
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	//队列不提供迭代器,更不支持随机访问
	while (!q.empty())
	{
		//输出队头元素
		cout << "队头元素--姓名:" << q.front().m_Name
			<< "年龄:" << q.front().m_Age << endl;
		//输出队尾元素
		cout << "队尾元素--姓名:" << q.back().m_Name
			<< "年龄:" << q.back().m_Age << endl;
		cout << endl;
		//弹出队头
		q.pop();
	}
	cout << "队列大小:" << q.size() << endl;
}
