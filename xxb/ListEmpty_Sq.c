#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"//判断线性表是否为空
struct ListEmpty_Sq(SqList L)
{
	if(L.elem)
    {          //判断线性表是否为空的前提是线性表存在，当首元素地址即L.elem存在时说明线性表存在
		if(L.length != 0)
		{               //如果线性表中元素为0，即L.length的值为0时说明线性表是空表
		       printf("线性表不是空表\n");
		       return FALSE;
        }
			else
			   printf("线性表是空表\n");
		return TRUE;
	}
	else
	printf("线性表不存在，无法判断\n");
	return OK;
}
