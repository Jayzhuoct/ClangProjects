#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"
//ȡջ��Ԫ��
void GetTop(SqStack S,SElemType *e)
{
    if(S.top==-1)printf("ERROR");
    *e=S.elem[S.top];
}
