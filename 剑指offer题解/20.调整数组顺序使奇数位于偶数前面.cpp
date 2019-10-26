/*

输入一个整数数组，实现一个函数来调整该数组中数字的顺序。

使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分。

样例
输入：[1,2,3,4,5]

输出: [1,3,5,2,4]

-----------------------------------------------------
算法
(双指针扫描) O(n)
用两个指针分别从首尾开始，往中间扫描。扫描时保证第一个指针前面的数都是奇数，第二个指针后面的数都是偶数。

每次迭代时需要进行的操作：

第一个指针一直往后走，直到遇到第一个偶数为止；
第二个指针一直往前走，直到遇到第一个奇数为止；
交换两个指针指向的位置上的数，再进入下一层迭代，直到两个指针相遇为止；
时间复杂度
当两个指针相遇时，走过的总路程长度是 n，所以时间复杂度是 O(n)。
*/

#include <vector>
using namespace std;

class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {
        int i = 0, j = array.size() - 1;
        while (i <= j)
        {
            while (i <= j && array[i] % 2 == 1)
                i++;
            while (i <= j && array[j] % 2 == 0)
                --j;
            if (i < j)
                swap(array[i], array[j]);
        }
    }
};
/*
若改成 需要考虑 数组的元素的相对顺序
可以采用冒泡排序的思想，冒泡排序是稳定的
*/
class Solution2
{
public:
    void reOrderArray(vector<int> &array)
    {
        int loop = array.size();
        bool change = true;
        while (change && loop--)
        {
            change = false;
            for (int i = 0; i < array.size(); i++)
            {
                if (array[i] % 2 == 0 && array[i + 1] % 2 == 1)
                {
                    swap(array[i], array[i + 1]);
                    change = true;
                }
            }
        }
    }
};