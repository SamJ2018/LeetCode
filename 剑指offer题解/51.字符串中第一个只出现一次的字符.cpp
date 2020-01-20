/*
���ַ������ҳ���һ��ֻ����һ�ε��ַ���

������"abaccdeff"�������b��

����ַ����в�����ֻ����һ�ε��ַ�������#�ַ���

������
���룺"abaccdeff"

�����'b'
*/
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    char firstNotRepeatingChar(string s)
    {
        unordered_map<char, int> count;
        for (auto c : s)
            count[c]++;
        char res = '#';
        for (auto c : s)
            if (count[c] == 1)
            {
                res = c;
                break;
            }
        return res;
    }
};