/*
输入n个整数，找出其中最小的k个数。

注意：

数据保证k一定小于等于输入数组的长度;
输出数组内元素请按从小到大顺序排序;
样例
输入：[1,2,3,4,5,6,7,8] , k=4

输出：[1,2,3,4]

------------------------------
创建一个大顶堆，保存k个元素，遍历数组，如果当前元素比堆顶元素小，那么就把元素放进去，然后把堆顶元素pop掉，保证堆里保存k个最小的元素。
*/
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k)
    {
    }
};