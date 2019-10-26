/*
实现函数double Power(double base, int exponent)，求base的 exponent次方。

不得使用库函数，同时不需要考虑大数问题。

注意：

不会出现底数和指数同为0的情况
样例1
输入：10 ，2

输出：100
样例2
输入：10 ，-2  

输出：0.01

--------------------------------------------------------------------------
算法
(模拟) O(n)
由于不需要考虑大数问题，所以我们直接循环连乘即可。

注意当指数是负数时，我们需要先取指数的绝对值，最后将乘积的倒数作为答案。

时间复杂度
假设指数是 n，则一共会循环 n 次，所以时间复杂度是 O(n)。

快速幂解法：
public class Solution {
    public static double Power(double base, int exp) {
 
        boolean flag = false;
        if (exp < 0) {
            flag = true;
            exp = -exp;
        }
        double ans = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                ans = ans * base;
            }
            exp >>= 1;
            base *= base;
        }
        return flag ? 1 / ans : ans;
    }
}
*/

/*
py
class Solution(object):
    def Power(self, base, exponent):
        """
        :type base: float
        :type exponent: int
        :rtype: float
        """
        v = 1
        if exponent < 0:
            exponent *= -1
            v = -1
        res = 1
        t = base
        while exponent:
            if exponent & 1 == 1:
                res = res * t
            t = t * t
            exponent >>= 1
        if v == -1:
            res = 1.0/res
        return res
*/

class Solution
{
public:
    double power(double base, int e)
    {
        int res = 1, f = 0;
        if (e < 0)
            f = 1, e *= -1;
        while (e)
        {
            if (e & 1)
                res = res * base;
            base *= base;
            e >>= 1;
        }
        if (f)
            return 1.0 / res;
        return res;
    }
};
