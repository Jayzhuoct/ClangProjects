#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"
//��ȡ���Ա�ĳһλ�ö�Ӧ��Ԫ��
struct GetElem_Sq(SqList *L,int index)
{
	int Num;
	if(index <= 0 || index > L.length)
	{              //���Ҫ��ȡԪ�ص�λ���Ƿ����
		printf("������һ����Ч������\n");
		return ERROR;
	}
	else
	Num = L.elem[index - 1];
	printf("��%d��λ�õ�Ԫ��Ϊ��%d\n",index,Num);
	return OK;
}
