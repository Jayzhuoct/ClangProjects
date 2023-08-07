#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
void InitStack_Sq(SqStack*S)
{
    int maxsize=STACK_INIT_SIZE;
    int incresize=STACKINCREMENT;
    S->elem=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S->elem)exit(OVERFLOW);
    S->top=-1;
    S->stacksize=maxsize;
    S->increment=incresize;
    printf("Initiative success!\n");
}
//Õ»µÄ³õÊ¼»¯
