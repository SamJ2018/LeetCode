/*
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����

������򷵻�true�����򷵻�false��

�������������������������ֶ�������ͬ��

����
���룺[4, 8, 6, 12, 16, 14, 10]

�����true

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