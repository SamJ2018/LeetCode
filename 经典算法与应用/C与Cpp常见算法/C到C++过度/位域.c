#include <stdio.h>
//位域  可以节约内存
struct digitplace
{
    //以下结构体实际只占用4字节
    unsigned int a : 5; //用unsigned防止因为符号位溢出
    unsigned int b : 4;
    unsigned int c : 16;

    //多个数据，按照类型重合
    //如果只有如下变量，按照int重合——>4字节
    //如果类型不一致  遵循结构体对齐规则
    unsigned int num1 : 1;
    unsigned int num2 : 1;
    //d.num1 = 2   X  不能越界，会截断
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

//1、判断 字节在内存中是低位还是高位存储
int isit()
{
    unsigned short num = 1; //0000 0000 0000 0001
    return (1 == *(char *)&num);
}

//2、显示整数   每个整数的内存形式
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

//3、现在电脑手机一般为低位低字节 （unix除外）

int main()
{

    double data = 1;
    int length = 8;
    struct bits *p = &data;
    while (length--) //遍历data的每一个字节
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