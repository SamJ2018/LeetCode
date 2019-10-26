/*

����һ���������飬ʵ��һ�����������������������ֵ�˳��

ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿�֡�

����
���룺[1,2,3,4,5]

���: [1,3,5,2,4]

-----------------------------------------------------
�㷨
(˫ָ��ɨ��) O(n)
������ָ��ֱ����β��ʼ�����м�ɨ�衣ɨ��ʱ��֤��һ��ָ��ǰ����������������ڶ���ָ������������ż����

ÿ�ε���ʱ��Ҫ���еĲ�����

��һ��ָ��һֱ�����ߣ�ֱ��������һ��ż��Ϊֹ��
�ڶ���ָ��һֱ��ǰ�ߣ�ֱ��������һ������Ϊֹ��
��������ָ��ָ���λ���ϵ������ٽ�����һ�������ֱ������ָ������Ϊֹ��
ʱ�临�Ӷ�
������ָ������ʱ���߹�����·�̳����� n������ʱ�临�Ӷ��� O(n)��
*/

#include <vector>
using namespace std;

class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {
        int i = 0, j = array.size() - 1;
        while (i <= j)
        {
            while (i <= j && array[i] % 2 == 1)
                i++;
            while (i <= j && array[j] % 2 == 0)
                --j;
            if (i < j)
                swap(array[i], array[j]);
        }
    }
};
/*
���ĳ� ��Ҫ���� �����Ԫ�ص����˳��
���Բ���ð�������˼�룬ð���������ȶ���
*/
class Solution2
{
public:
    void reOrderArray(vector<int> &array)
    {
        int loop = array.size();
        bool change = true;
        while (change && loop--)
        {
            change = false;
            for (int i = 0; i < array.size(); i++)
            {
                if (array[i] % 2 == 0 && array[i + 1] % 2 == 1)
                {
                    swap(array[i], array[i + 1]);
                    change = true;
                }
            }
        }
    }
};