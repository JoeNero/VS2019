/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

输入：(5) + (5)
输出：0 -> 1 

*/
#include <iostream>
#include <ctime>
#include "List.h"

using namespace std;
typedef Node ListNode ;
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* head = new Node(0);
	ListNode* cur = head;
	ListNode* p1 = l1;
	ListNode* p2 = l2;
	int carry = 0;
	while (p1 != nullptr || p2 != nullptr)
	{
		int x = (p1 != nullptr) ? p1->data : 0;
		int y = (p2 != nullptr) ? p2->data : 0;
		int sum = carry + x + y;
		carry = sum / 10;
		cur->next = new Node(sum % 10);
		cur = cur->next;
		if (p1 != nullptr) p1 = p1->next;
		if (p2 != nullptr) p2 = p2->next;
	}
	if (carry > 0)
	{
		cur->next = new Node(carry);
	}
	return head->next;
}

int main()
{
	Node* head1 = createList();
	Node* head2 = createList();
	pushBack(head1, 2);
	pushBack(head1, 4);
	pushBack(head1, 3);

	pushBack(head2, 5);
	pushBack(head2, 6);
	pushBack(head2, 4);
	printList(head1);
	printList(head2);

	Node* dest = addTwoNumbers(head1, head2);

	printList(dest);

	return 0;
}
