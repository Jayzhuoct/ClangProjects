#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"
//获取线性表某一位置对应的元素
struct GetElem_Sq(SqList *L,int index)
{
	int Num;
	if(index <= 0 || index > L.length)
	{              //如果要获取元素的位置是否出界
		printf("请输入一个有效的数字\n");
		return ERROR;
	}
	else
	Num = L.elem[index - 1];
	printf("第%d个位置的元素为：%d\n",index,Num);
	return OK;
}
