#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

void DestroyList(Sqlist *L)
{
    int i;
    for(i=0;i<L->length;i++)
    {
        L->elem[i]=0;
        free(L->elem[i]);
    }
    L->length=0;
    L->listsize=0;
    printf("Destroy Succecc!!\n");
}
