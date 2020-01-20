/*
����ַ������ҳ�һ����Ĳ������ظ��ַ������ַ��������������ַ����ĳ��ȡ�

�����ַ�����ֻ�����ӡ�a������z�����ַ���

����
���룺"abcabc"

�����3
*/

#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int longestSubstringWithoutDuplication(string s)
    {
        unordered_map<char, int> count;
        int res = 0;
        for (int i = 0, j = 0; j < s.size(); j++)
        {
            if (++count[s[j]] > 1)
            {
                while (count[s[i]] == 1)
                    count[s[i++]]--;
                count[s[i++]]--;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};