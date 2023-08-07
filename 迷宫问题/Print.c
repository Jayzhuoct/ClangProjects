#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#define m 6
#define n 8
#define STACK_INIT_SIZE 100
//打印路径
void Print(int sum,SqStack a)
{
	int i;
	printf("迷宫的第%d条路径如下:\n",sum);
	for(i=0;i<=a.top;i++)
    printf("(%d,%d)->",a.stack[i].x,a.stack[i].y);
	printf("出口\n\n");
	printf("\n");
}
