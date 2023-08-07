#include "List.h"
#include <stdio.h>
#include <stdlib.h>
int BiTreeDepth(BiTree *T,int h,int depth)
{
    if(T)
    {
        if(h>depth)depth=h;
        {
            depth=BiTreeDepth(T->lchild,h+1,depth);
            depth=BiTreeDepth(T->rchild,h+1,depth);
        }
    }
    return depth;
}
