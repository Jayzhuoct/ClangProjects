#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"


int main()
{
    Sqlist L;
    InitList(&L);
    Sqlist Lb;
    InitList(&Lb);
    ElemType m;
    char a[20]="abdskfklaw";
    char b[20]="abdskfklaw";
    for(int i=0;i<10;i++)
    {
        ListInsert(&L,i+1,a[i]);
    }
    for(int i=0;i<10;i++)
    {
        ListInsert(&Lb,i+1,b[i]);
    }
    printf("-ListInsert_display-\n");
    printf("L->length = %d\n",L.length);
    printf("Lb->length = %d\n",Lb.length);
    print(L);
    print(Lb);
    printf("-Listcompare-\n");
     printf("L->length = %d\n",L.length);
    printf("%d\n",listcompare(L,Lb));

    printf("-ListDelete-\n");
    ListDelete(&L,2,&m);
    printf("m = %c\n",m);
    print(L);
    printf("-ClaerList-\n");
    ClearList(&L);
    printf("-SqListlength-\n");
    printf("L->length = %d\n",L.length);
    printf("Lb->length = %d\n",Lb.length);
    printf("-DstroysqList-\n");
    DestroyList(&L);

    return 0;
}

