#include <stdio.h>
#include <stdlib.h>
#include "Lnode.h"
void DestroyList(LinkList L)
{
    LNode *p=L;
    p=L->next;
    while(p!=NULL)
    {
        L->next=p->next;
        free(p);
        p=L->next;
    }
    printf("destroy success\n");
}
