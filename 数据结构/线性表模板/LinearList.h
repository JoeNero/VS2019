#ifndef __LINEAELIST_H
#define __LINEAELIST_H

#include <iostream>
using namespace std;

//内存不足
class NoMem
{
public:
	NoMem() {};
};
void my_new_handler()
{
	throw NoMem();
}

new_handler Old_Handler_ = set_new_handler(my_new_handler);

template<class T>
class LinearList
{
public:
	LinearList(int MaxListSize = 10);			//构造函数
	~LinearList() { delete[] element; }			//析构函数

	bool Find(int k, T& x) const;				//返回第k个元素至x中
	int Search(const T& x) const;				// 返回x所在位置
	LinearList<T>& Delete(int k, T& x);			// 删除第k个元素并将它返回至x中
	LinearList<T>& Insert(int k, const T& x);	// 在第k个元素之后插入x

	bool IsEmpty() const { return length == 0; }
	int Length() const { return length; }

	void Output(ostream& out) const;

private:
	int length;
	int MaxSize;
	T* element; // 一维动态数组
};



//基于公式线性表构造函数
template<class T>
inline LinearList<T>::LinearList(int MaxListSize)
{
	MaxSize = MaxListSize;
	element = new T[MaxSize];
	length = 0;
}

//检测是否在线性表中
template<class T>
bool LinearList<T>::Find(int k, T& x) const
{
	//把第k个元素放到x中
	//如果不存在第k个元素则返回false,否在返回true
	if (k < 1 || k>length)
	{
		return false;
	}
	else
	{
		x = element[k - 1];
		return true;
	}
}

//查找数据
template<class T>
int  LinearList<T>::Search(const T& x) const				// 返回x所在位置
{
	for (int i = 0; i < length; i++)
	{
		//查找x,找到返回索引
		if (x == element[i])
		{
			return ++i;
		}
		else
		{
			//未找到，不在表中，返回0
			return 0;
		}
	}
}

//删除
template<class T>
LinearList<T>& LinearList<T>::Delete(int k, T& x)
{
	//把第k个元素放入到x中,然后删除第k个元素
	//如果不存在第k个元素,则引发索引越界异常
	if (Find(k, x))
	{
		//把k+1以及以后的元素向前移动一个位置
		for (int i = k; i < length; i++)
		{
			element[i-1] = element[i];
		}
		length--;
		return *this;
	}
	else
	{
		throw "删除的索引越界";
	}
}
template<class T>
LinearList<T>& LinearList<T>::Insert(int k,const T&x)
{
	if (k < 0 || k > length)
	{
		throw "插入索引越界";
	}
	else
	{
		if (length == MaxSize) throw NoMem();
		for (int i = length - 1; i >= k; i--)
		{
			element[i+1] = element[i];
		}
		element[k] = x;
		length++;
		return *this;
	}
}

template<class T>
void LinearList<T>::Output(ostream& out) const
{
	for (int i = 0; i < length; i++)
	{
		out << element[i] << " ";
	}
}
//重载<<
template<class T>
ostream& operator<<(ostream& out, const LinearList<T>& x)
{
	x.Output(out);
	return out;
}


#endif // !__LINEAELIST_H