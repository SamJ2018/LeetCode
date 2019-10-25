/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be �� k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.


��֪һ��ʹ���ַ�����ʾ�ķǸ�����num����num�е�k�������Ƴ������Ƴ�k�����ֺ󣬿��Ի�õ���С�Ŀ��ܵ������֡�
���� : num = ��1432219�� , k = 3
��ȥ��3�����ֺ�õ��ĺܶ�ܶ�������1432�� 4322�� 2219�� 1219�� 1229...��
ȥ������4�� 3�� 2�õ���1219��С��

1.�����num�� �ַ�������<=10002�������ַ�������>=k
2.�����num�ַ����������κ�������0�ַ���ͷ


˼����
1.���������ֶ�ɨ����ɺ� k��Ȼ>0��Ӧ���������Ĵ���
����: num = 12345�� k = 3 ʱ��
2.����������0����ʱ��Ӧ�������������⴦��
����: num = 100200, k = 1 ʱ��
3.��ν�������洢Ϊ�ַ���������?
*/

#include "util.h"

class Solution
{
public:
	string removeKdigits(string num, int k)
	{
		vector<int> S; //ʹ��vector����ջ�����������󷵻�
		string result = ""; //�洢���ս�����ַ���

		for (int i = 0; i < num.length(); i++)  //�����λѭ��ɨ������num
		{
			int number = num[i] - '0';  //���ַ��͵�numת��Ϊ����ʹ��
			while (S.size() != 0 && S[S.size() - 1] > number && k > 0) //��ջ���գ�ջ������number ��Ȼ����ɾ������ʱ����ѭ��
			{
				S.pop_back();  //����ջ��Ԫ��
				k--;
			}
			if (number != 0 || S.size() != 0) //ȷ��ǰ׺��Ϊ0
			{
				S.push_back(number);  //������numberѹ��ջ��
			}
		}

		while (S.size() != 0 && k > 0)
		{
			//ջ���գ�˵�����ǵ������� ��Ȼ����ɾ��ĩβԪ��
			S.pop_back();
			k--;   //����ջ��������k
		}
		
		for (int i = 0; i < S.size(); i++)
		{
			result.append(1, '0' + S[i]); //��ջ�е�Ԫ�ش�ͷ�������洢��result��
		}

		if (result == "") //resultΪ�գ��򷵻�0
			result = "0";

		return result;
	}
};