#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"//对线性表进行赋值
struct ValueList_Sq(SqList *L)
{
	int i,j;
	printf("请输入线性表元素的个数：");
	scanf("%d",&i);
	if(i > L.listsize)                     //如果当要输入的元素个数大于内存大小时
	{
		while(1)             //一直开辟新空间，直到开辟的空间大于需要的空间为止
		{
			if(i > L.listsize){
				L->elem = (ElemType *)realloc(L->elem,LISTINCREMENT * sizeof(ElemType));
				L->listsize += LISTINCREMENT;
        /*realloc()函数：重新分配空间
		           参数：原空间基址，现需空间大小
		           返回：1.成功：新空间地址(本质上是一个数值)
		                 2.失败：Null*/
			}
			else
			break;
		}
	}
	for(j = 0;j < i;j++){
		printf("请输入第%d个元素：",j + 1);
	    scanf("%d",&L.elem[j]);
	}
	L.length = i;          //赋值完成后，修改并保存线性表的长度
	printf("赋值成功\n");
	return OK;
}
