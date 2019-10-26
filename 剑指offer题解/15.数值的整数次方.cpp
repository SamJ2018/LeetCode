/*
ʵ�ֺ���double Power(double base, int exponent)����base�� exponent�η���

����ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣

ע�⣺

������ֵ�����ָ��ͬΪ0�����
����1
���룺10 ��2

�����100
����2
���룺10 ��-2  

�����0.01

--------------------------------------------------------------------------
�㷨
(ģ��) O(n)
���ڲ���Ҫ���Ǵ������⣬��������ֱ��ѭ�����˼��ɡ�

ע�⵱ָ���Ǹ���ʱ��������Ҫ��ȡָ���ľ���ֵ����󽫳˻��ĵ�����Ϊ�𰸡�

ʱ�临�Ӷ�
����ָ���� n����һ����ѭ�� n �Σ�����ʱ�临�Ӷ��� O(n)��

�����ݽⷨ��
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
