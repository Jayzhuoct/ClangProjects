#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 30
#include"header.h"
int isempty(ST *T)
{
	if(T->top<0)
		return 1;
	else
		return 0;
}
