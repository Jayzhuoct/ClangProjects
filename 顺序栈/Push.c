#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"
//��ջ����
void Push(SqStack *S,SElemType e)
{
    if(S->top==S->stacksize)incrementStacksize(S);
    S->top++;
    S->elem[S->top]=e;
}
