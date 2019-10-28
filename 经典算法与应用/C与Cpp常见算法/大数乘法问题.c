/*
C++ �� C�нṹ�������
C�Ľṹ�������Ҫ��struct����
�޼̳С��ڲ�������Ȩ�޶�����
*/
#include <stdio.h>
#include <string.h>
void getBidata(char *data_a, char *data_b)
{
    int length_a = strlen(data_a), length_b = strlen(data_b);

    int *pres = (int *)malloc(sizeof(int) * (length_a + length_b));

    memset(pres, 0, sizeof(int) * (length_a + length_b)); //��ʼ��
    //�۳�
    for (int i = 0; i < length_a; i++)
        for (int j = 0; j < length_b; j++)
            pres[i + j + 1] += (data_a[i] - '0') * (data_b[j] - '0'); //ע��i+j+1  �ַ���ĩβΪ'\0'

    for (int i = length_a + length_b - 1; i >= 0; i--)
        if (pres[i] >= 10)                              //ֻ��>=10����Ҫ��λ
            pres[i - 1] += pres[i] / 10, pres[i] %= 10; //��λ����ȡ��λ   ע�������Ǵ�������-> �������Ǵ�������

    int i = 0;
    while (pres[i] == 0)
        i++; //ǡ�ò�Ϊ0��λ�� ����0ȥ��

    char *lastres = (char *)malloc(sizeof(char) * (length_a + length_b));
    int j;
    for (j = 0; j < length_a + length_b; j++, i++)
        lastres[j] = pres[i] + '0';

    lastres[j] = '\0';
    printf("last���=%s", lastres);
}

void main()
{
    char str1[100] = {0};
    char str2[100] = {0};
    scanf("%s%s", str1, str2);
    printf("str1=%s,str2=%s", str1, str2);
    getBidata(str1, str2);
    system("pause");
}