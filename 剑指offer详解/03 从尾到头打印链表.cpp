/*
����һ������������ֵ��β��ͷ��˳�򷵻�һ��ArrayList��
���룺[2, 3, 5]
���أ�[5, 3, 2]
*/
#include "util.h"

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

class Solution {
public:
	vector<int> printListFromTailToHead(struct ListNode* head) {
		vector<int> value;
		if (head != NULL)
		 {
			value.insert(value.begin(), head->val);
			if (head->next != NULL)
			{
				vector<int> tempVec = printListFromTailToHead(head->next);
				if (tempVec.size() > 0)
				value.insert(value.begin(), tempVec.begin(), tempVec.end());
			}

		}
		return value;
	}
};
