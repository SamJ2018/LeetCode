/*
��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������

���磬�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ��

����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�

ע��:

С������û���������֣�����.123����0.123��
С����������û�����֣�����233.����233.0��
С����ǰ��ͺ�����������֣�����233.666;
��e��Eǰ��û������ʱ�������ַ������ܱ�ʾ���֣�����.e1��e1��
��e��E����û������ʱ�������ַ������ܱ�ʾ���֣�����12e��12e+5.4;
������
����: "0"

���: true
-----------------------------------------------------------
�㷨
(ģ�⣬�ַ�������) O(n)
��ȥ�����׺���β�ո�
���������һ�������ţ�ֱ�Ӻ��ԣ�
����ַ���Ϊ�ջ�ֻ��һ��'.'������һ���Ϸ�����
ѭ�������ַ�����ȥ�����¼��������
(1) '.'��'e'����1��;
(2) '.'��'e'������֣�
(3) 'e'�����ǰ��Ϊ�գ�����'e'ǰ�������'.'��
(4) 'e'��������������ţ��������ź���Ϊ�գ�
ʣ�µ�������Ϸ���
ʱ�临�Ӷȷ����������ַ���ֻ����һ�飬����ʱ�临�Ӷ��� O(n)��
*/
#include <cstring>
#include <string>
using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        int i = 0, j = s.size();
        while (i <= j && s[i] == ' ')
            ++i;
        while (i <= j && s[j] == ' ')
            --j;
        if (i > j)
            return false;
        s = s.substr(i, j - i + 1);
        if (s[0] == '+' || s[0] == '-')
            s = s.substr(1);

        if (s.empty() || s[0] == '.' && s.size() == 1)
            return false; //ȥ��+,-,.

        int dot = 0, e = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                ;
            else if (s[i] == '.')
            {
                dot++;
                if (dot > 1 || e)
                    return false; //xxxxx.xxxxx.xxxxx    xxxxexxxx.xxxx
            }
            else if (s[i] == 'e' || s[i] == 'E')
            {
                e++;
                if (!i || i + 1 == s.size() || e > 1 || s[i - 1] == '.' && i == 1)
                    return false; //exxxx  ,xxxxe, xxxexxxx
                if (s[i + 1] == '+' || s[i + 1] == '-')
                {
                    if (i + 2 == s.size())
                        return false; //xxxe+
                    i++;
                }
            }
            else
                return false;
        }
        return true;
    }
};

class Solution2
{
public:
    bool isNumeric(char *str)
    {
        // ��Ƿ��š�С���㡢e�Ƿ���ֹ�
        bool sign = false, decimal = false, hasE = false;
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == 'e' || str[i] == 'E')
            {
                if (i == strlen(str) - 1)
                    return false; // e����һ��Ҫ������
                if (hasE)
                    return false; // ����ͬʱ��������e
                hasE = true;
            }
            else if (str[i] == '+' || str[i] == '-')
            {
                // �ڶ��γ���+-���ţ�����������e֮��
                if (sign && str[i - 1] != 'e' && str[i - 1] != 'E')
                    return false;
                // ��һ�γ���+-���ţ��Ҳ������ַ�����ͷ����Ҳ���������e֮��
                if (!sign && i > 0 && str[i - 1] != 'e' && str[i - 1] != 'E')
                    return false;
                sign = true;
            }
            else if (str[i] == '.')
            {
                // e���治�ܽ�С���㣬С���㲻�ܳ�������
                if (hasE || decimal)
                    return false;
                decimal = true;
            }
            else if (str[i] < '0' || str[i] > '9') // ���Ϸ��ַ�
                return false;
        }
        return true;
    }
};