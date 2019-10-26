/*
��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��

ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ���0�Σ���

�ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ��

���磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ�䡣

����
���룺

s="aa"
p="a*"

���:true

----------------------------------------------------------------------
�㷨
(��̬�滮) O(nm)
״̬��ʾ��f[i][j]��ʾp��j��ʼ����β���Ƿ���ƥ��s��i��ʼ����β
״̬ת�ƣ�

���p[j+1]����ͨ���'*'����f[i][j]���棬���ҽ���s[i]���Ժ�p[j]ƥ�䣬��f[i+1][j+1]���棻
���p[j+1]��ͨ���'*'������������ֻҪ��һ�����㣬f[i][j]�����棻
f[i][j+2]���棻
s[i]���Ժ�p[j]ƥ�䣬��f[i+1][j]���棻
��1������µ�״̬ת�ƺܺ���⣬�ǵ�2������µ�״̬ת����ô����أ�

��ֱ�۵�ת�Ʒ�ʽ�������ģ�ö��ͨ���'*'����ƥ����ٸ�p[j]��ֻҪ��һ���������ƥ�䣬��f[i][j]�����棻
�������Ļ������Ƿ��֣�f[i][j]����ö��0��p[j]֮�⣬�����ö�ٲ�����������f[i+1][j]���ˣ���������ֻ���ж�
f[i+1][j]�Ƿ�Ϊ�棬�Լ�s[i]�Ƿ���Ժ�p[j]ƥ�伴�ɡ�

ʱ�临�Ӷȷ�����n ��ʾs�ĳ��ȣ�m ��ʾp�ĳ��ȣ��ܹ� nm ��״̬��״̬ת�Ƹ��Ӷ� O(1)��������ʱ�临�Ӷ��� O(nm).
*/
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int n, m;
    vector<vector<int>> f;
    string s, p;

    bool isMatch(string _s, string _p)
    {
        s = _s, p = _p;
        n = s.size(), m = p.size();
        f = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
        return dp(0, 0);
    }

    bool dp(int x, int y)
    {
        if (f[x][y] != -1)
            return f[x][y];
        if (y == m)
            return f[x][y] = x == n;
        bool first_match = x < n && (p[y] == '.' || s[x] == p[y]);
        if (y + 1 < m && p[y + 1] == '*')
            f[x][y] = dp(x, y + 2) || first_match && dp(x + 1, y); //x+1
        else
            f[x][y] = first_match && dp(x + 1, y + 1);
        return f[x][y];
    }
};

class Solution2
{
public:
    bool match(char *str, char *pattern)
    {
        if (*str == '\0' && *pattern == '\0')
            return true;
        if (*str != '\0' && *pattern == '\0')
            return false;
        if (*(pattern + 1) != '*')
        {
            if (*str == *pattern || (*str != '\0' && *pattern == '.'))
                return match(str + 1, pattern + 1);
            else
                return false;
        }
        else
        {
            if (*str == *pattern || (*str != '\0' && *pattern == '.'))
                return match(str, pattern + 2) || match(str + 1, pattern);
            else
                return match(str, pattern + 2);
        }
    }
};