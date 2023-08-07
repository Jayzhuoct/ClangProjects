#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main()
{
    BiTree *T;
    T=CreatBiTree(T);
    PreOrderTraserve(T);
    printf("\n");
    InOrderTraverse(T);
    printf("\n");
    PostOrderTraverse(T);
    int h,depth;
    h=1;
    depth=0;
    depth=BiTreeDepth(T,h,depth);
    printf("\n%d\n",depth);
    BiTree *TT;
    TT=CreatBiTree(TT);
    TT=CopyTree(TT);
    printf("\n");
    PostOrderTraverse(TT);
    return 0;
}
