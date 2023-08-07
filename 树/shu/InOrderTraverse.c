#include "List.h"
#include <stdio.h>
#include <stdlib.h>
void InOrderTraverse(BiTree *T)
{
    if(T)
    {
        PreOrderTraserve(T->lchild);
        printf("%c ",T->data);
        PreOrderTraserve(T->rchild);
    }
}
