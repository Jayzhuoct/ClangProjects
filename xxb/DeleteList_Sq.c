//删除线性表某一位置的元素
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"
struct DeleteList_Sq(SqList *L,int i)
{
	int *p,*q;
	if(i < 1 || i > L->length)
    {            //如果要删除的位置不合法
		printf("请输入一个有效数字\n");
		return ERROR;
	}
	p = &(L->elem[i - 1]);                 //p为被删除元素的位置
	q = L->elem + L->length - 1;            //将表尾元素的位置赋值给q
	for(++p;p <= q;p++)
    *(p - 1) = *p;                    //被删除的元素之后的元素全部左移
	--L->length;                           //表长减1
	printf("第%d个元素删除成功\n",i);
	return OK;
}
