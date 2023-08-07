#include "List.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

BiTree *InitBiTree(BiTree *T)
{
    T=(BiTree *)malloc(sizeof(BiTree));
    T->data=NULL;
    T->lchild=NULL;
    T->rchild=NULL;
    return T;
}
