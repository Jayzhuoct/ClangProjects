#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 30
#include"header.h"
int isfull(ST *T)
{
	if(T->top==N-1)
		return 1;
	else
		return 0;
}
