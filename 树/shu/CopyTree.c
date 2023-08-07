#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
BiTree *CopyTree(BiTree *T)
{
    if(!T)
    {
        return NULL;
    }
    BiTree *lptr;
    lptr=(BiTree *)malloc(sizeof(BiTree));
    if(T->lchild)
    {
        lptr=CopyTree(T->lchild);
    }
    else
    {
        lptr=NULL;
    }
    BiTree *rptr;
    rptr=(BiTree *)malloc(sizeof(BiTree));
    if(T->rchild)
    {
        rptr=CopyTree(T->rchild);
    }
    else
    {
        rptr=NULL;
    }
    BiTree *TT;
    TT=(BiTree *)malloc(sizeof(BiTree));
    TT=GetTreeNode(T->data,lptr,rptr);
    return TT;
}
