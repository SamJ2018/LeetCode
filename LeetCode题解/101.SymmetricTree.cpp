/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

	1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
	1
   / \
  2   2
   \   \
   3    3
*/

//version A recursion 递归版
#include "util.h"

class Solution {
public:
	/*递归版本和第100题相似，唯一不同的是需要判断的是左子树和右子树是否相等*/
	bool helpFun(TreeNode* p, TreeNode* q)
	{
		if (p == NULL && q == NULL) return true;
		if (p != NULL && q != NULL && p->val == q->val)
		{
			return helpFun(p->left, q->right) && helpFun(p->right, q->left);
		}
		return false;
	}
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		return helpFun(root->right, root->left);
	}
};

//version B non-recursion 非递归版
bool isSymmetric(TreeNode* root) {
	if (!root) return true;
	stack<TreeNode*> sl, sr;
	sl.push(root);
	sr.push(root);
	TreeNode* lp = root->left, * rp = root->right;
	while (lp || !sl.empty() || rp || !sl.empty()) {
		if ((!lp && rp) || (lp && !rp)) return false;
		if (lp && rp) {
			if (lp->val != rp->val) return false;
			sl.push(lp);
			sr.push(rp);
			lp = lp->left;
			rp = rp->right;
		}
		else {
			lp = sl.top()->right;
			rp = sr.top()->left;
			sl.pop();
			sr.pop();
		}
	}
	return true;
}