#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#define m 6
#define n 8
#define STACK_INIT_SIZE 100


int main()
{
	SqStack *s;
	s=(SqStack *)malloc(sizeof(SqStack));
	s->stack[0].x=1;
	s->stack[0].y=1;
	s->top=0;
	t[1][1]=maze[1][1]=1;
	path(1,1,*s);
	return 0;
}

