#include <stdio.h>
//λ��  ���Խ�Լ�ڴ�
struct digitplace
{
    //���½ṹ��ʵ��ֻռ��4�ֽ�
    unsigned int a : 5; //��unsigned��ֹ��Ϊ����λ���
    unsigned int b : 4;
    unsigned int c : 16;

    //������ݣ����������غ�
    //���ֻ�����±���������int�غϡ���>4�ֽ�
    //������Ͳ�һ��  ��ѭ�ṹ��������
    unsigned int num1 : 1;
    unsigned int num2 : 1;
    //d.num1 = 2   X  ����Խ�磬��ض�
};

int main2()
{
    printf("%d", sizeof(struct digitplace));
    struct digitplace d, *p;
    p = &d;
    d.a = 8;
    d.b = 11;
    d.c = 2018;

    return 0;
}

//1���ж� �ֽ����ڴ����ǵ�λ���Ǹ�λ�洢
int isit()
{
    unsigned short num = 1; //0000 0000 0000 0001
    return (1 == *(char *)&num);
}

//2����ʾ����   ÿ���������ڴ���ʽ
struct bits
{
    unsigned char ch1 : 1;
    unsigned char ch2 : 1;
    unsigned char ch3 : 1;
    unsigned char ch4 : 1;
    unsigned char ch5 : 1;
    unsigned char ch6 : 1;
    unsigned char ch7 : 1;
    unsigned char ch8 : 1;
};

//3�����ڵ����ֻ�һ��Ϊ��λ���ֽ� ��unix���⣩

int main()
{

    double data = 1;
    int length = 8;
    struct bits *p = &data;
    while (length--) //����data��ÿһ���ֽ�
    {
        printf("%d%d%d%d %d%d%d%d ",
               (p + length)->ch8,
               (p + length)->ch7,
               (p + length)->ch6,
               (p + length)->ch5,
               (p + length)->ch4,
               (p + length)->ch3,
               (p + length)->ch2,
               (p + length)->ch1);
    }

    short num = 1;
    printf("\n %d", isit());
    return 0;
}