#include "util.h"
/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

已知k个已排序链表头节点指针，将这k个链表合并，合并后仍为有序的，返回合并后的头节点
*/

/*利用STL和排序算法*/
bool cmp(const ListNode* a, const ListNode* b)
{
	return a->val < b->val;  //比较函数，从小到大排序
}
class Solution
{
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) 
	{
		vector<ListNode*>node_vec;
		for (int i = 0; i < lists.size(); i++)
		{
			//遍历k个链表，将节点全部添加到node_vec
			ListNode* head = lists[i];
			while (head)
			{
				node_vec.push_back(head);
				head = head->next;
			}
		}
		if (node_vec.size() == 0)
		{
			return NULL;
		}

		sort(node_vec.begin(), node_vec.end(), cmp);

		for (int i = 1; i < node_vec.size(); i++)
		{
			//链接新的链表
			node_vec[i - 1]->next = node_vec[i];
		}

		node_vec[node_vec.size() - 1]->next = NULL;

		return node_vec[0];
	}
};


/*
思路2：对k个链表进行分治，两两进行合并
	设有k个链表，平均每个链表有n个节点，时间复杂度：
		第1轮，进行k/2，每次处理2n个数字
		第2轮，进行k/4，每次处理4n个数字
		...
		最后一次：进行k/(2^logk)次，每次处理2^logk *N个值
		时间复杂度：O(kNlogk)
*/

//分治法
class Solution_2 
{
public:
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		if (lists.size() == 0)
			return NULL;

		if (lists.size() == 1)
			return lists[0];

		if (lists.size() == 2)
			return MergeTwoLists(lists[0], lists[1]);
	
		int mid =  lists.size()/2;

		//拆分lists为两个子lists
		vector<ListNode*> sub1_lists;
		vector<ListNode*> sub2_lists;

		for (int i = 0; i < mid; i++)
			sub1_lists.push_back(lists[i]);

		for (int i = mid; i < lists.size(); i++)
			sub2_lists.push_back(lists[i]);

		ListNode* l1 = mergeKLists(sub1_lists);
		ListNode* l2 = mergeKLists(sub2_lists);

		return MergeTwoLists(l1, l2);//分治处理
	}

};


int main_23()
{
	ListNode a(3), b(2), c(5), d(0);
	vector<ListNode*>node_vec;
	node_vec.push_back(&a);
	node_vec.push_back(&b);
	node_vec.push_back(&c);
	node_vec.push_back(&d);

	sort(node_vec.begin(), node_vec.end(), cmp);

	for (int i = 0; i < node_vec.size(); i++)
	{
		printf("%d\n", node_vec[i]->val);
	}

	return EXIT_SUCCESS;
}
#if 0
void MIN_HEAP_SORT(struct ListNode** lists, int index_i, int size)
{
	int left = index_i * 2 + 1;
	int right = index_i * 2 + 2;
	if (left >= size)
		return;
	int min;
	if (right >= size)
		min = left;
	else
		min = lists[left]->val < lists[right]->val ? left : right;
	if (lists[index_i]->val > lists[min]->val) {
		struct ListNode* temp = lists[index_i];
		lists[index_i] = lists[min];
		lists[min] = temp;
		MIN_HEAP_SORT(lists, min, size);
	}
}

void BuildHeap(struct ListNode** lists, int size)
{
	for (int i = (size - 1) / 2; i >= 0; --i)
	{
		MIN_HEAP_SORT(lists, i, size);
	}
}

struct ListNode* mergeKLists(struct ListNode* lists[], int k) 
{
	if (k == 0)
		return NULL;//1
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* int_max = (struct ListNode*)malloc(sizeof(struct ListNode));
	int_max->val = INT_MAX;
	int_max->next = NULL;
	struct ListNode* travel = head;
	for (int i = 0; i < k; ++i) 
	{
		if (lists[i] == NULL)
			lists[i] = int_max;
	}/*remove those NULL ptr*/
	BuildHeap(lists, k);
	while (lists[0] != int_max)
	{
		travel->next = lists[0];
		travel = lists[0];
		lists[0] = lists[0]->next;
		if (lists[0] == NULL)
			lists[0] = int_max;
		MIN_HEAP_SORT(lists, 0, k);
	}
	travel->next = NULL;
	return head->next;
}
#endif


