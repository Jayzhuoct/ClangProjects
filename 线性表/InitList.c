#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

void InitList(Sqlist *L)
{
    L->elem =(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L->elem) exit(OVERFLOW);
    L->length=0;L->listsize=LIST_INIT_SIZE;
    printf("initialize Suceess!!\n");
}
