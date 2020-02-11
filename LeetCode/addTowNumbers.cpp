/*
�������� �ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ��� ���� �ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�

��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�

�����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��

ʾ����

���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 0 -> 8
ԭ��342 + 465 = 807

���룺(5) + (5)
�����0 -> 1 

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
