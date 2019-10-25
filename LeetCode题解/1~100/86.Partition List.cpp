/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/
#include "util.h"

/*
已知链表指针head与数值X，将所有小于x的节点放在大于或等于x的节点前，
且保持这些节点的原来的相对位置
思路：
	设置两个临时头结点less_head和more_head，将大于等于3的节点依次链接到more_head后面
	然后将小于3的x的节点的依次链接到less_head后面，less_ptr是工作指针，最后将less_ptr的next指针链接到more_head的next指针上
*/

class Solution 
{
public:
	ListNode* partition(ListNode* head, int x)
	{
		//设置两个临时的头节点
		ListNode less_head(0),more_head(0);

		//两个工作指针
		ListNode* less_ptr = &less_head;
		ListNode* more_ptr = &more_head;

		while (head)
		{
			//如果节点值小于x，则将该节点插入到less_ptr中
			if (head->val < x)
			{
				less_ptr->next = head;
				less_ptr = head; //链接完后，less_ptr向后移动，指向head
			}
			else
			{
				//否则插入到more_ptr后
				more_ptr->next = head;
				more_ptr = head;
			}
			//继续遍历链表
			head = head->next;
		}
		less_ptr->next = more_head.next;//将less链表尾，与more链表头相连
		more_ptr->next = NULL; //将more_ptr(即为链表尾节点)next置空
		return less_head.next; //less_head的next节点即为新链表头结点，返回即可
	}
};


//for test
int main_1()
{
	ListNode a(1), b(4), c(3), d(2), e(5), f(2);
	a.next = &b;  b.next = &c;  c.next = &d;   d.next = &e;  e.next = &f;

	Solution solve;
	ListNode* head = solve.partition(&a, 3);
	
	while (head)
	{
		cout << head->val;
		head = head->next;
	}

	return EXIT_SUCCESS;
}