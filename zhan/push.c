#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
void push_Sq(SqStack S,SElemType*e)
{
    if(S->top==S->stacksize)incrementStacksize(S);
    S->top++;
    S->elem[S->top]=e;
}
