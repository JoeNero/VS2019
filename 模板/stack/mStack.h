#ifndef _MSTACK_H
#define _MSTACK_H
//栈模板
const int max = 1000;

template<class T>
class MyStack
{
public:
	T stk[max];
	int top;
	MyStack();
	bool stackfull();
	bool stacknull();
	void push(T x);
	T pop();
};


#endif // !_MSTACK_H

template<class T>
inline MyStack<T>::MyStack()
{
	top = 0;
}

template<class T>
inline bool MyStack<T>::stackfull()
{
	if (top == max-1)return true;
	return false;
}

template<class T>
inline bool MyStack<T>::stacknull()
{
	if (top == 0)return true;
	return false;
}

template<class T>
inline void MyStack<T>::push(T x)
{
	if (stackfull()) return;
	stk[top++] = x;
}

template<class T>
inline T MyStack<T>::pop()
{
	if (stackfull()) return 1;
	return stk[--top];
}
