#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#define m 6
#define n 8
#define STACK_INIT_SIZE 100
//��ӡ·��
void Print(int sum,SqStack a)
{
	int i;
	printf("�Թ��ĵ�%d��·������:\n",sum);
	for(i=0;i<=a.top;i++)
    printf("(%d,%d)->",a.stack[i].x,a.stack[i].y);
	printf("����\n\n");
	printf("\n");
}
