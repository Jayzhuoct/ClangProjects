#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"
void DestroyStack(SqStack *S)
{
    free(&S->elem[S->top--]);
    printf("Destroy success!\n");
}
