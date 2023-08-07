#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 30
#include"header.h"
int pop(ST *T)
{
	int x;
	if(T->top<0)
	{
		printf("Zhan is empty,can not pop!\n");
		exit(0);
	}
	else
	{
		x=T->a[T->top];
		(T->top)--;
		return x;
	}
}
