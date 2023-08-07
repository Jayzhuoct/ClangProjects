#include "List.h"
#include <stdio.h>
#include <stdlib.h>

BiTree *GetTreeNode(TElemType item,BiTree *lptr,BiTree *rptr)
{
    BiTree *T;
    T=(BiTree *)malloc(sizeof(BiTree));
    T->data=item;
    T->lchild=lptr;
    T->rchild=rptr;
    return T;
}
