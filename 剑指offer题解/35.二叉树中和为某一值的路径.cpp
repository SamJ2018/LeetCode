/*
输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。

从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

样例
给出二叉树如下所示，并给出num=22。
      5
     / \
    4   6
   /   / \
  12  13  6
 /  \    / \
9    1  5   1

输出：[[5,4,12,1],[5,6,6,5]]

---------------------------------------------------------------

*/
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector <vector<int>> ans;
    vector<int> path;

    vector <vector<int>> findPath(TreeNode *root, int sum) {
        dfs(root, sum);
        return ans;
    }

    void dfs(TreeNode *root, int sum) {
        if (!root) return;
        path.push_back(root->val);
        sum -= root->val;
        if (!root->left && !root->right && !sum)
            ans.push_back(path);
        dfs(root->left,sum);
        dfs(root->right,sum);
        path.pop_back();
    }
};