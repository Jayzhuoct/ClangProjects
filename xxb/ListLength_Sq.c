//获取线性表的长度
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"
struct ListLength_Sq(SqList L)
{
	if(L.elem)
	{              //判断当前线性表存在
		int K;
		K = L.length;        //将线性表的元素个数赋值给K
		printf("线性表长度为%d\n",K);
		return OK;
	}
	else
		printf("线性表不存在，无法判断\n");
	return OK;
}
