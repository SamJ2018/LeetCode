/*
����һ�����ǵݼ�˳��������������� A������ÿ�����ֵ�ƽ����ɵ������飬Ҫ��Ҳ���ǵݼ�˳������



ʾ�� 1��

���룺[-4,-1,0,3,10]
�����[0,1,9,16,100]
ʾ�� 2��

���룺[-7,-3,2,3,11]
�����[4,9,9,49,121]


��ʾ��

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A �Ѱ��ǵݼ�˳������

*/

int *sortedSquares(int *A, int ASize, int *returnSize)
{
	int *head = A, *tail = A + ASize - 1, index;
	int *ret = malloc(sizeof(int) * ASize);
	for (index = ASize - 1; head <= tail && index >= 0; index--)
	{
		/* ȡ����ֵ */
		*head = (*head) > 0 ? (*head) : ((*head)*-1);
		*tail = (*tail) > 0 ? (*tail) : ((*tail)*-1);
		if (*head >= *tail)
		{
			ret[index] = (*head)*(*head);
			head++;
		}
		else
		{
			ret[index] = (*tail)*(*tail);
			tail--;
		}
	}
	return ret;
}