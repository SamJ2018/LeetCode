/*
从上到下按层打印二叉树，同一层的结点按从左到右的顺序打印，每一层打印到一行。

样例
输入如下图所示二叉树[8, 12, 2, null, null, 6, null, 4, null, null, null]
    8
   / \
  12  2
     /
    6
   /
  4

输出：[[8], [12, 2], [6], [4]]

-----------------------------------
算法
(BFS) O(n)
宽度优先遍历，一层一层来做。即：

将根节点插入队列中；
创建一个新队列，用来按顺序保存下一层的所有子节点；
对于当前队列中的所有节点，按顺序依次将儿子加入新队列，并将当前节点的值记录在答案中；
重复步骤2-3，直到队列为空为止。
时间复杂度
树中每个节点仅会进队出队一次，所以时间复杂度是 O(n)。
*/
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<vector<int>> printFromTopToBottom(TreeNode *root)
    {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode* >q;
        q.push(root);q.push(nullptr);
        vector<int> level;
        while(q.size()){
            auto t=q.front();
            q.pop();
            if(!t){
                if(level.empty()) break;
                res.push_back(level);
                level.clear();
                q.push(nullptr);
                continue;
            }
            level.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        return res;
    }
};