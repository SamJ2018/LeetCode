/*
����һ�ö�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����

�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����

����
����������������ʾ��������num=22��
      5
     / \
    4   6
   /   / \
  12  13  6
 /  \    / \
9    1  5   1

�����[[5,4,12,1],[5,6,6,5]]

---------------------------------------------------------------

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
    vector<vector<int>> findPath(TreeNode *root, int sum)
    {
    }
};