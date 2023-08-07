#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#define m 6
#define n 8
#define STACK_INIT_SIZE 100
//符合规则的压入栈
void Push_SqStack(SqStack *s,SElemType x)
{
	if(s->top==STACK_INIT_SIZE-1)
		printf("\n栈满!");
	else
	{
		s->top++;
		s->stack[s->top]=x;
	}
}


//检查栈是否为空
int Empty_SqStack(SqStack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}


//删除栈顶的元素，退后操作
void Pop_SqStack(SqStack *s)
{
	if(Empty_SqStack(s))
	{
		printf("\n栈空!");
		exit(0);
	}
	else
	{
		s->top--;
	}
}
