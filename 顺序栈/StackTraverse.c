#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"
//����ջ�����������
void StackTraverse(SqStack S)
{
    for(int i=0;i<=S.top;i++)
        printf("%d",S.elem[i]);
    printf("\n");
}
