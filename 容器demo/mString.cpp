/*
创建者	:	XTT
功能	:	String类操作

时间	:	2020/01/07
*/

#include <iostream>
#include <string>

using namespace std;

void test01();						//string类构造demo
void test02();						//string类赋值demo
void test03();						//string类拼接demo
void test04();						//string类查找demo
void test05();						//string类替换demo
void test06();						//string类比较demo
void test07();						//string类插入删除demo


int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	system("pause");
	return 0;
}

/*
功能: 	- string类构造demo
		@param
		@param
		@param
描述	:
示例	:	  
*/
void test01()
{
	string s1; //创建空字符串，调用无参构造函数
	cout << "str1 = " << s1 << endl;
	const char* str = "hello world";
	string s2(str); //把c_string转换成了string
	cout << "str2 = " << s2 << endl;
	string s3(s2); //调用拷贝构造函数
	cout << "str3 = " << s3 << endl;
	string s4(10, 'a');
	cout << "str4 = " << s4 << endl;
}

/*
功能: 	- string类赋值demo
		@param
		@param
		@param
描述	:
示例	:
*/
void test02()
{
	string str1;
	str1 = "hello world";
	cout << "str1 = " << str1 << endl;
	string str2;
	str2 = str1;
	cout << "str2 = " << str2 << endl;
	string str3;
	str3 = 'a';
	cout << "str3 = " << str3 << endl;
	string str4;
	str4.assign("hello c++");
	cout << "str4 = " << str4 << endl;
	string str5;
	str5.assign("hello c++", 5);
	cout << "str5 = " << str5 << endl;
	string str6;
	str6.assign(str5);
	cout << "str6 = " << str6 << endl;
	string str7;
	str7.assign(5, 'x');
	cout << "str7 = " << str7 << endl;
}

/*
功能: 	- string类拼接demo
		@param
		@param
		@param
描述	:
示例	:
*/
void test03()
{
	string str1 = "我";
	str1 += "爱玩游戏";
	cout << "str1 = " << str1 << endl;
	str1 += ':';
	cout << "str1 = " << str1 << endl;
	string str2 = "LOL DNF";
	str1 += str2;
	cout << "str1 = " << str1 << endl;
	string str3 = "I";
	str3.append(" love ");
	str3.append("game abcde", 4);
	//str3.append(str2);
	str3.append(str2, 4, 3); // 从下标4位置开始 ，截取3个字符，拼接到字符串末尾
	cout << "str3 = " << str3 << endl;
}

/*
功能: 	- string类查找demo
		@param
		@param
		@param
描述	:
示例	:
*/
void test04()
{
	//查找
	string str1 = "abcdefgde";
	int pos = str1.find("de");
		if (pos == -1)
		{
		cout << "未找到" << endl;
		} 
		else	
		{
		cout << "pos = " << pos << endl;
		} 
		pos = str1.rfind("de");
		cout << "pos = " << pos << endl;
}

/*
功能: 	- string类替换demo
		@param
		@param
		@param
描述	:
示例	:
*/
void test05()
{
	//替换
	string str1 = "abcdefgde";
	str1.replace(1, 4, "1111");
	cout << "str1 = " << str1 << endl;
}

/*
功能: 	- string类比较demo
		@param
		@param
		@param
描述	:
示例	:
*/
void test06()
{
	string s1 = "aello";
	string s2 = "hello";
	int ret = s1.compare(s2);
	if (ret == 0) {
		cout << "s1 等于 s2" << endl;
	} 
	else if (ret > 0)
	{
		cout << "s1 大于 s2" << endl;
	} 
	else
	{
	cout << "s1 小于 s2" << endl;
	}
}

/*
功能: 	- string类插入删除demo
		@param
		@param
		@param
描述	:
示例	:
*/
void test07()
{
	string str = "hello";
	str.insert(1, "111");
	cout << str << endl;
	str.erase(1, 3); //从1号位置开始3个字符
	cout << str << endl;
}