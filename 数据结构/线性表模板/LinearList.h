#ifndef __LINEAELIST_H
#define __LINEAELIST_H

#include <iostream>
using namespace std;

//�ڴ治��
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
	LinearList(int MaxListSize = 10);			//���캯��
	~LinearList() { delete[] element; }			//��������

	bool Find(int k, T& x) const;				//���ص�k��Ԫ����x��
	int Search(const T& x) const;				// ����x����λ��
	LinearList<T>& Delete(int k, T& x);			// ɾ����k��Ԫ�ز�����������x��
	LinearList<T>& Insert(int k, const T& x);	// �ڵ�k��Ԫ��֮�����x

	bool IsEmpty() const { return length == 0; }
	int Length() const { return length; }

	void Output(ostream& out) const;

private:
	int length;
	int MaxSize;
	T* element; // һά��̬����
};



//���ڹ�ʽ���Ա��캯��
template<class T>
inline LinearList<T>::LinearList(int MaxListSize)
{
	MaxSize = MaxListSize;
	element = new T[MaxSize];
	length = 0;
}

//����Ƿ������Ա���
template<class T>
bool LinearList<T>::Find(int k, T& x) const
{
	//�ѵ�k��Ԫ�طŵ�x��
	//��������ڵ�k��Ԫ���򷵻�false,���ڷ���true
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

//��������
template<class T>
int  LinearList<T>::Search(const T& x) const				// ����x����λ��
{
	for (int i = 0; i < length; i++)
	{
		//����x,�ҵ���������
		if (x == element[i])
		{
			return ++i;
		}
		else
		{
			//δ�ҵ������ڱ��У�����0
			return 0;
		}
	}
}

//ɾ��
template<class T>
LinearList<T>& LinearList<T>::Delete(int k, T& x)
{
	//�ѵ�k��Ԫ�ط��뵽x��,Ȼ��ɾ����k��Ԫ��
	//��������ڵ�k��Ԫ��,����������Խ���쳣
	if (Find(k, x))
	{
		//��k+1�Լ��Ժ��Ԫ����ǰ�ƶ�һ��λ��
		for (int i = k; i < length; i++)
		{
			element[i-1] = element[i];
		}
		length--;
		return *this;
	}
	else
	{
		throw "ɾ��������Խ��";
	}
}
template<class T>
LinearList<T>& LinearList<T>::Insert(int k,const T&x)
{
	if (k < 0 || k > length)
	{
		throw "��������Խ��";
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
//����<<
template<class T>
ostream& operator<<(ostream& out, const LinearList<T>& x)
{
	x.Output(out);
	return out;
}


#endif // !__LINEAELIST_H