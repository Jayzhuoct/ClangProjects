#include "SqList.h"
#include "malloc.h"
SqList InitList(SqList L)
{
    L.elem=(SqList *)malloc(sizeof(ElemType)*80);
    if(!L.elem) exit(1);
    L.length=0;
    L.listsize=80;
    printf("OK");
    return L;
}
