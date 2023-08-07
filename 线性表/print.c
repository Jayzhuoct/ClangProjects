#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

void print(Sqlist L)
{
    int n;
    for(n=0;n<L.length;n++)
    {
        printf("%c\t",L.elem[n]);
    }
    printf("\n");
}
