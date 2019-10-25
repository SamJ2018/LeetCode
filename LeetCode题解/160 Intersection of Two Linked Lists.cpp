#include "util.h"
#include <set>
/*
Write a program to find the node at which the intersection of two singly linked lists begins.

example 1
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). 
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. 
There are 2 nodes before the intersected node in A; 
There are 3 nodes before the intersected node in B.

example 2
Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Reference of the node with value = 2
Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). 
From the head of A, it reads as [0,9,1,2,4]. From the head of B, it reads as [3,2,4]. 
There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.

example 3
Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: null
Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. 
Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

class Solution {
private:
#if 0
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		std::set<ListNode*> node_set;
		while (headA) {  //设置查找集合node_test
			node_set.insert(headA);   //将链表A中的节点插入node_test
			headA = headA->next;
		}
		while (headB) {
			if (node_set.find(headB) != node_set.end()) {
				return headB;
			}
			headB = headB.next;
		}
		return NULL;
	}

	int sameNode()
	{
		std::set<int> test_set;  //STL中的set方法
		const int A_LEN = 7; //测试数组A和B的长度
		const int B_LEN = 8;

		int a[A_LEN] = { 5,1,4,8,10,1,3 };
		int b[B_Len] = { 2,7,6,1,6,0,1 };

		for (int i = 0; i < A_LEN; i++)
			test_set.insert(a[i]);  //将数组a的元素插入set

		for(int i=0;i<B_LEN;i++)  //检查 数组b中元素 是否在set中
			if (test_set.find(b[i]) != test_set.end()) {
				printd("b[%d]=%d in array A.\n", i, b[i]);
			}

		return 0
	}

#endif
};