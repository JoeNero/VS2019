#include <iostream>
#include "mStack.h"

using namespace std;

int main()
{
	MyStack<double> st;
	st.push(1.1);
	st.push(2.2);
	st.push(3.3);
	while (!st.stacknull())
	{
		cout << st.pop() << endl;
	}
	return 0;
}