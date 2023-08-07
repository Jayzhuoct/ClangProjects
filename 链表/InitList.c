#include <stdio.h>
#include <stdlib.h>
#include "Lnode.h"
LinkList InitList(LinkList L)
{
    L=(LinkList)malloc(sizeof(LNode));
    if(!L)exit(OVERFLOW);
    L->next=NULL;
    printf("initialize success!\n");
    return L;
}
