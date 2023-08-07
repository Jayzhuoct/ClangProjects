#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"//打印线性表
struct PrintList_Sq(SqList L)
{
	printf("当前线性表的元素为：");
	for(int K = 0;K < L.length;K++)      //遍历当前线性表
	    printf("  %d",L.elem[K]);
	printf("\n");                        //换行
	return OK;
}
