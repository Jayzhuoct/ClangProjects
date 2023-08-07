//在线性表某一位置插入元素
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"
struct ListInsert_Sq(SqList *L,int i,ElemType e)
{
	ElemType *newbase;
	int *q,*p;
	if(i < 1 || i > L->length+1)         //判断插入位置的index值是否合法
	    return ERROR;
	if(L->length >= L->listsize)
	{         //如果当前线性表存储空间已满，增加分配
		newbase = (ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)
		{                 //如果存储空间分配失败，则执行异常退出
			printf("存储空间分配失败\n");
			exit(OVERFLOW);
		}
		L->elem = newbase;               //新的存储空间基址
		L->listsize += LISTINCREMENT;
	}
	q = &(L->elem[i-1]);                 //L.elem[index-1]为数组中的最后一个元素，q为要插入的位置
	for(p = &(L->elem[L->length - 1]);p >= q;--p)
    *(p+1) = *p;                    //要插入位置以及之后的位置向后移
	*q = e;                             //将e插入到想要插入的位置
	++L->length;                         //插入新的元素之后表长加1
	printf("元素插入成功\n");
	return OK;
}
