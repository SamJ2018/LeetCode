/*
���ϵ��°����ӡ��������ͬһ��Ľ�㰴�����ҵ�˳���ӡ��ÿһ���ӡ��һ�С�

����
��������ͼ��ʾ������[8, 12, 2, null, null, 6, null, 4, null, null, null]
    8
   / \
  12  2
     /
    6
   /
  4

�����[[8], [12, 2], [6], [4]]

-----------------------------------
�㷨
(BFS) O(n)
������ȱ�����һ��һ������������

�����ڵ��������У�
����һ���¶��У�������˳�򱣴���һ��������ӽڵ㣻
���ڵ�ǰ�����е����нڵ㣬��˳�����ν����Ӽ����¶��У�������ǰ�ڵ��ֵ��¼�ڴ��У�
�ظ�����2-3��ֱ������Ϊ��Ϊֹ��
ʱ�临�Ӷ�
����ÿ���ڵ������ӳ���һ�Σ�����ʱ�临�Ӷ��� O(n)��
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
    }
};