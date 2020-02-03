/*
������	:	XTT
����	:	String�����

ʱ��	:	2020/01/07
*/

#include <iostream>
#include <string>

using namespace std;

void test01();						//string�๹��demo
void test02();						//string�ำֵdemo
void test03();						//string��ƴ��demo
void test04();						//string�����demo
void test05();						//string���滻demo
void test06();						//string��Ƚ�demo
void test07();						//string�����ɾ��demo


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
����: 	- string�๹��demo
		@param
		@param
		@param
����	:
ʾ��	:	  
*/
void test01()
{
	string s1; //�������ַ����������޲ι��캯��
	cout << "str1 = " << s1 << endl;
	const char* str = "hello world";
	string s2(str); //��c_stringת������string
	cout << "str2 = " << s2 << endl;
	string s3(s2); //���ÿ������캯��
	cout << "str3 = " << s3 << endl;
	string s4(10, 'a');
	cout << "str4 = " << s4 << endl;
}

/*
����: 	- string�ำֵdemo
		@param
		@param
		@param
����	:
ʾ��	:
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
����: 	- string��ƴ��demo
		@param
		@param
		@param
����	:
ʾ��	:
*/
void test03()
{
	string str1 = "��";
	str1 += "������Ϸ";
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
	str3.append(str2, 4, 3); // ���±�4λ�ÿ�ʼ ����ȡ3���ַ���ƴ�ӵ��ַ���ĩβ
	cout << "str3 = " << str3 << endl;
}

/*
����: 	- string�����demo
		@param
		@param
		@param
����	:
ʾ��	:
*/
void test04()
{
	//����
	string str1 = "abcdefgde";
	int pos = str1.find("de");
		if (pos == -1)
		{
		cout << "δ�ҵ�" << endl;
		} 
		else	
		{
		cout << "pos = " << pos << endl;
		} 
		pos = str1.rfind("de");
		cout << "pos = " << pos << endl;
}

/*
����: 	- string���滻demo
		@param
		@param
		@param
����	:
ʾ��	:
*/
void test05()
{
	//�滻
	string str1 = "abcdefgde";
	str1.replace(1, 4, "1111");
	cout << "str1 = " << str1 << endl;
}

/*
����: 	- string��Ƚ�demo
		@param
		@param
		@param
����	:
ʾ��	:
*/
void test06()
{
	string s1 = "aello";
	string s2 = "hello";
	int ret = s1.compare(s2);
	if (ret == 0) {
		cout << "s1 ���� s2" << endl;
	} 
	else if (ret > 0)
	{
		cout << "s1 ���� s2" << endl;
	} 
	else
	{
	cout << "s1 С�� s2" << endl;
	}
}

/*
����: 	- string�����ɾ��demo
		@param
		@param
		@param
����	:
ʾ��	:
*/
void test07()
{
	string str = "hello";
	str.insert(1, "111");
	cout << str << endl;
	str.erase(1, 3); //��1��λ�ÿ�ʼ3���ַ�
	cout << str << endl;
}