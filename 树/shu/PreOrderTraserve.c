#include "List.h"
#include <stdio.h>
#include <stdlib.h>
void PreOrderTraserve(BiTree *T)
{
    if(T)
    {
        printf("%c ",T->data);
        PreOrderTraserve(T->lchild);
        PreOrderTraserve(T->rchild);
    }
}
