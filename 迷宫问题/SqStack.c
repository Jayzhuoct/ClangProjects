#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#define m 6
#define n 8
#define STACK_INIT_SIZE 100
//���Ϲ����ѹ��ջ
void Push_SqStack(SqStack *s,SElemType x)
{
	if(s->top==STACK_INIT_SIZE-1)
		printf("\nջ��!");
	else
	{
		s->top++;
		s->stack[s->top]=x;
	}
}


//���ջ�Ƿ�Ϊ��
int Empty_SqStack(SqStack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}


//ɾ��ջ����Ԫ�أ��˺����
void Pop_SqStack(SqStack *s)
{
	if(Empty_SqStack(s))
	{
		printf("\nջ��!");
		exit(0);
	}
	else
	{
		s->top--;
	}
}
