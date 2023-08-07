//对线性表进行销毁
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"
struct DistoryList_Sq(SqList *L)
{
	if(!L->elem)
    {
	  printf("您还未建立线性表，请先建立线性表\n");
	  return ERROR;
	}
	free(L->elem);            //使用free函数，将之前动态分配的内存还给系统
	L->elem = NULL;           //重置elem的值为Null
	L->length = 0;            //将线性表的元素个数重置为0
	L->listsize = 0;          //将线性表的存储容量重置为0
	printf("线性表已经销毁\n");
	return OK;
}
