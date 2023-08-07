//构造一个空的线性表
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"
struct InitList_Sq(SqList *L)
{
	L->elem=(ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));      //L.elem为首元素的地址
	if(!L->elem)
    {            //如果存储空间分配失败，L.elem为NULL
	printf("存储空间分配失败\n");
	exit(OVERFLOW);
	}
	L->length = 0;            //当前线性表为空表，即线性表长度为0
	L->listsize = LIST_INIT_SIZE;           //给线性表分配初始容量
	printf("一个空的线性表已经构建成功\n");      //输出空线性表构建成功的提示消息
	return OK;
}
