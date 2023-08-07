#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
void DestroyStack(SqStack*S,SElemType*e)
{
    free(&S->elem[S->top--]);
    printf("Destroy success!\n");
}
