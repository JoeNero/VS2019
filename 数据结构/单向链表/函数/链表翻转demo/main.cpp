#include <iostream>
#include "ListPoint.h"

using namespace std;

int main()
{
	Node* n1 = new Node;
	for (size_t i = 0; i < 9; i++)
	{
		pushBack(n1, i);
	}
	printList(n1);
	reverse(n1);
	printList(n1);
	return 0;
}

