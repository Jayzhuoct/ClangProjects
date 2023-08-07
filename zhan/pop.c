#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
void Pop_Sq(SqStack*S,SElemType*e)
{
    if(S->top==-1)
        printf("ERROR");
    *e=S->elem[S->top--];
}
