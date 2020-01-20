/*
C++ 和 C中结构体的区别：
C的结构体变量需要用struct声明
无继承、内部方法、权限定符等
*/
#include <stdio.h>
#include <string.h>
void getBidata(char *data_a, char *data_b)
{
    int length_a = strlen(data_a), length_b = strlen(data_b);

    int *pres = (int *)malloc(sizeof(int) * (length_a + length_b));

    memset(pres, 0, sizeof(int) * (length_a + length_b)); //初始化
    //累乘
    for (int i = 0; i < length_a; i++)
        for (int j = 0; j < length_b; j++)
            pres[i + j + 1] += (data_a[i] - '0') * (data_b[j] - '0'); //注意i+j+1  字符串末尾为'\0'

    for (int i = length_a + length_b - 1; i >= 0; i--)
        if (pres[i] >= 10)                              //只有>=10才需要进位
            pres[i - 1] += pres[i] / 10, pres[i] %= 10; //进位，并取各位   注意数组是从左往右-> 但运算是从右向左

    int i = 0;
    while (pres[i] == 0)
        i++; //恰好不为0的位置 ，把0去掉

    char *lastres = (char *)malloc(sizeof(char) * (length_a + length_b));
    int j;
    for (j = 0; j < length_a + length_b; j++, i++)
        lastres[j] = pres[i] + '0';

    lastres[j] = '\0';
    printf("last结果=%s", lastres);
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