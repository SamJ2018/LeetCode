/*
��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ���

���磬�����ַ�����ֻ����ǰ�����ַ���go��ʱ����һ��ֻ����һ�ε��ַ��ǡ�g����

���Ӹ��ַ����ж���ǰ�����ַ���google��ʱ����һ��ֻ����һ�ε��ַ��ǡ�l����

�����ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ���

����
���룺"google"

�����"ggg#ll"

���ͣ�ÿ���ַ�������һ���ַ����ͽ���һ���жϲ������ǰ�ĵ�һ��ֻ����һ�ε��ַ���
---------------------------
˫ָ��or��������

*/
#include <unordered_map>
#include <queue>
using namespace std;
class Solution
{
public:
    unordered_map<char, int> count;
    queue<int> q;
    //Insert one char from stringstream
    void insert(char ch)
    {
        if (++count[ch] > 1)
            while (q.size() && count[q.front()] > 1)
                q.pop();
        else
            q.push(ch);
    }
    //return the first appearence once char in current stringstream
    char firstAppearingOnce()
    {
        if (q.empty())
            return '#';
        return q.front();
    }
};