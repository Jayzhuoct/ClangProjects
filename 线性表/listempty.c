#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

int listempty(Sqlist *L)
{
    if(L->length==0)
        return 1;
    else return 0;
}
