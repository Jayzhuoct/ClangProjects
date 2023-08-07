#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#define m 6
#define n 8
#define STACK_INIT_SIZE 100

typedef struct
{
	int x,y;
}SElemType;

typedef struct
{
	SElemType stack[STACK_INIT_SIZE];
	int top;
}SqStack;

typedef struct
{
	int x,y;
}Item;

int maze[m+2][n+2];
void path(int x,int y,SqStack elem);
void Print(int sum,SqStack a);
void Push_SqStack(SqStack *s,SElemType x);
int Empty_SqStack(SqStack *s);
void Pop_SqStack(SqStack *s);
int sum;
int t[m+2][n+2];
Item Move[8];


#endif // HEADER_H_INCLUDED
