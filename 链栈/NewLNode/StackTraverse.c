#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"

void StackTraverse(LinkStack S)
{
    LNode *p=S;
    while(p)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}
