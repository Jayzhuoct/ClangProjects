#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
void StackTraverse_Sq(SqStack S)
{
for(int i=0;i<=S.top;i++)
printf("%d ",S.elem[i]);
printf("\n");
}
