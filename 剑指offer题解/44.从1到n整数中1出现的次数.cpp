/*
����һ������n�����1��n��n��������ʮ���Ʊ�ʾ��1���ֵĴ�����

��������12����1��12��Щ�����а�����1����������1��10��11��12�����С�1��һ��������5�Ρ�

����
���룺 12
����� 5

˼·��
����  abcdef 
���cΪ1 ��ôǰ��λ���Դ�00~ab-1  ����λ���Դ�000~def
���ab��Ϊ1 ��ôc��Ϊ������� ��cΪ0 ��0��1   c=1ʱ0~def  c>1  000~999
*/
#include <vector>
using namespace std;
class Solution
{
public:
    int numberOf1Between1AndN_Solution(int n)
    {
        if (!n)
            return 0;
        vector<int> number;
        while (n)
            number.push_back(n % 10), n /= 10; //��ÿһλȡ��
        int res = 0;
        for (int i = number.size() - 1; i >= 0; i--)
        {
            auto left = 0, right = 0, t = 1;
            // �൱����12x34  x������ left=12  right=34  t�൱���㷶Χ
            for (int j = number.size() - 1; j > i; j--)
                left = left * 10 + number[j];
            for (int j = i - 1; j >= 0; j--)
                right = right * 10 + number[j], t *= 10;
            res += left * t;
            if (number[i] == 1)
                res += right + 1;
            else if (number[i] > 1)
                res += t;
        }
        return res;
    }
};