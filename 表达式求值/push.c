#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 30
#include"header.h"
void push(ST *T,int s)
{
	if(T->top==N-1)
	{
		printf("Zhan is full,can not push,you can modify N and then you can push again.\n");
		exit(0);
	}
	else
	{
		(T->top)++;
		T->a[T->top]=s;
	}
}
