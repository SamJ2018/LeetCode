#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Data
{
    long long number;
    char *pstr;
    int strlen;
};

struct Array
{
    struct Data *parr;
    int len;
    char soft[0]; //柔性数组，不占用空间
};

void main()
{
    //总结： 指针用-> 结构体变量使用 .
    struct Array *p = malloc(sizeof(struct Array));
    p->len = 10;
    //p->parr = malloc(sizeof(struct Data) * p->len);
    (*p).parr = malloc(sizeof(struct Data) * p->len);

    p->parr[0].number = 10000000;
    (p->parr + 0)->number = 2000000; //

    p->parr[0].pstr = malloc(10);
    strcpy(p->parr[0].pstr, "almost10");
    p->parr[0].strlen = 10;
}