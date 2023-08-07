#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

BiTree *CreatBiTree(BiTree *T)
{
    char ch;
    ch=getchar();
    if(ch=='#')
    {
        T=NULL;
    }
    else
    {
         T=(BiTree *)malloc(sizeof(BiTree));
         T->data=ch;
         T->lchild=CreatBiTree(T->lchild);
         T->rchild=CreatBiTree(T->rchild);
    }
    return T;
}
