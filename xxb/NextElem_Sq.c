#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"//求线性表某一元素的后继
void NextElem_Sq(SqList L,int i)
{
	int K;
	if(L.elem)
    {          //判断线性表是否为空的前提是线性表存在，当首元素地址即L.elem存在时说明线性表存在
	    if(i <= 1 || i > L.length - 1)              //判断输入的i值是否合法
        printf("请输入一个有效数字\n");
		K = L.elem[i];        //将第i个元素的后一个元素赋值给K
		printf("第%d个位置的直接后继为：%d\n",i,K);
	}
	else
		printf("线性表不存在，无法判断\n");
	return OK;
}
