//对线性表进行重置
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"
struct ClearList_Sq(SqList *L)
{
	if(L->elem)
    {                            //如果线性表存在
	    L->length = 0;            //将线性表的元素个数重置为0
	    printf("线性表已重置\n");
	    return OK;
	}
	else
	printf("线性表不存在，无法重置\n");
	return OK;
}
