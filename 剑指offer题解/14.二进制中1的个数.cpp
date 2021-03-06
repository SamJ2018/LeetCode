/*
输入一个32位整数，输出该数二进制表示中1的个数。

注意：

负数在计算机中用其绝对值的补码来表示。
样例1
输入：9
输出：2
解释：9的二进制表示是1001，一共有2个1。
样例2
输入：-2
输出：31
解释：-2在计算机里会被表示成11111111111111111111111111111110，
      一共有31个1。
------------------------------------------------------------------
算法
(位运算) O(logn)
迭代进行如下两步，直到 n 变成0为止：

如果 n 在二进制表示下末尾是1，则在答案中加1；
将 n 右移一位，也就是将 n 在二进制表示下的最后一位删掉；
这里有个难点是如何处理负数。
在C++中如果我们右移一个负整数，系统会自动在最高位补1，这样会导致 n 永远不为0，就死循环了。
解决办法是把 n 强制转化成无符号整型，这样 n 的二进制表示不会发生改变，但在右移时系统会自动在最高位补0。

时间复杂度
每次会将 n 除以2，最多会除 logn 次，所以时间复杂度是 O(logn)。
*/

class Solution
{
public:
    int NumberOf1(int _n)
    {
        unsigned int n = _n; //为了防止死循环，有符号数补1 无符号数补0
        int s = 0;
        while (n)
            s += n & 1, n >>= 1;
        return s;
    }
};