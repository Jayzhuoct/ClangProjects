#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"

void incrementStacksize(SqStack *s)
{
    SElemType*p=(SElemType*)malloc((STACK_INIT_SIZE+STACKINCREMENT)*sizeof(SElemType));
    if(!p) exit(OVERFLOW);
    SElemType*q;
    for(int i=0;i<STACK_INIT_SIZE;i++)
    {
        p[i]=s->elem[i];
    }
    p=s->elem;
    s->elem=p;
    free(q);
}
