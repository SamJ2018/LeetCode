/*
����һ������Ϊ n+1 ������nums�����������е������� 1?n �ķ�Χ�ڣ����� n��1��
���ҳ�����������һ���ظ��������������޸���������顣

����
���� nums = [2, 3, 5, 4, 3, 2, 6, 7]��

���� 2 �� 3��
˼���⣺���ֻ��ʹ�� O(1) �Ķ���ռ䣬����ô���أ�
 */

//˼·������nums���飬���±�Ϊi��Ԫ�����±�Ϊnums[i]��Ԫ������򷵻أ����򽻻�������жϡ�ע�⣺��Ҫ�ҳ����ٷ�Χ�ڵ���

class Solution
{
public:
    int duplicateInArray(vector<int> &nums)
    {
        int n = nums.size();
        for (auto x : nums)
            if (x < 0 || x >= n)
                return -1;

        for (int i = 0; i < n; i++)
        {
            while (i != nums[i] && nums[nums[i]] != nums[i]) //�Լ�����Ҫ���Լ��Ƚ�
                swap(nums[i], nums[nums[i]]);
            if (nums[i] != i && nums[nums[i]] == nums[i])
                return nums[i];
        }
        return -1; //û���ҵ�
    }
};