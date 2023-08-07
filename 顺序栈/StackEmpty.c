#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"

int StackEmpty(SqStack S)
{
    if(S.top==-1)return 1;
    else return 0;
}
