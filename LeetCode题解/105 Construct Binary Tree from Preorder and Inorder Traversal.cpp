/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

	3
   / \
  9  20
	/  \
   15   7
*/
#include "util.h"
struct TreeNode* buildTree(int* preorder, int* inorder, int n) {
	if (n == 0)
		return NULL;

	struct TreeNode* root = (TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = preorder[0];

	int rootIndex;
	for (rootIndex = 0; inorder[rootIndex] != root->val; ++rootIndex);

	root->left = rootIndex == 0 ? NULL : buildTree(preorder + 1, inorder, rootIndex);

	root->right = rootIndex == n - 1 ? NULL : buildTree(preorder + rootIndex + 1, inorder + rootIndex + 1, n - rootIndex - 1);

	return root;
}