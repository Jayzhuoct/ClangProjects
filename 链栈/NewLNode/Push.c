#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

void Push(LinkStack *S,SElemType e)
{
    LNode *p;
    p=(LNode *)malloc(sizeof(LNode));
    p->data=e;
    p->next=*S;
    *S=p;
}

