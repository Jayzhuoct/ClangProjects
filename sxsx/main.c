#include <stdio.h>
#include <stdlib.h>
#include "Sqlist.h"
int main
{
    Sqlist L;
    InitSqlist(&L);
    Sqlist Lb;
    InitSqlist(&Lb);

    ElemType m;
    char a[20]="absdfgbfga";
    char b[20]="absdfgbfga";

    for(int i=0;i<10;i++)
    {
        ListInsert_Sq(&L,i++,a[i]);
    }
    for(int i=0;i<10;i++)
    {
        ListInsert_Sq(&Lb,i+1,b[i]);
    }
    printf("--------ListInsert display--------\n");
    display Sqlist(L);
    printf("\n");
    display Sqlist(Lb);
    printf("\n");
    printf("--------Listcompare--------\n");
    printf("%d\n",listcompare1(L.Lb));
    printf("--------ListDelete_Sq------\n");
    ListDelete_Sq(&L,2,&m);
    printf("%c\n",m);
    display_Sqlist(L);
    printf("\n");
    printf("-------ClearList--------\n");
    ClearList_Sq(&L);
    printf("-------sqListength--------\n");
    printf("L.length=%d\n",L.length);
    printf("L.length=%d\n",Lb.length);
    printf("--------DestroysqList---------\n");
    DestroyList(&L);
    return 0;
}
