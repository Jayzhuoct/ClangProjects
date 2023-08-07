#include "List.h"
#include <stdio.h>
#include <stdlib.h>

void PostOrderTraverse(BiTree *T)
{
    if(T)
    {
        PreOrderTraserve(T->lchild);
        PreOrderTraserve(T->rchild);
        printf("%c ",T->data);
    }
}
