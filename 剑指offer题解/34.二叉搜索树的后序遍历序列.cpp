/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。

如果是则返回true，否则返回false。

假设输入的数组的任意两个数字都互不相同。

样例
输入：[4, 8, 6, 12, 16, 14, 10]

输出：true

------------------------------------------

*/
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> seq;

    bool verifySequenceOfBST(vector<int> sequence) {
        seq = sequence;
        return dfs(0, seq.size() - 1);
    }

    bool dfs(int l, int r) {
        if (l >= r) return true;
        int root = seq[r];
        int k = l;
        while (k < r && seq[k] < root) k++;
        for (int i = k; i < r; i++)
            if (seq[i] < root) return false;
        return dfs(l, k - 1) && dfs(k + 1, r - 1);
    }
};