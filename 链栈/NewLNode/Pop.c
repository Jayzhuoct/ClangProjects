#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

void Pop(LinkStack *S,SElemType *e)
{
    LNode *p;
    if(*S!=NULL)
    {
        p=*S;
        *S=(*S)->next;
        *e=p->data;
        free(p);
        printf("%d",*e);
    }
}
