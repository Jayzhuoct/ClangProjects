//��ȡ���Ա�ĳ���
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"
struct ListLength_Sq(SqList L)
{
	if(L.elem)
	{              //�жϵ�ǰ���Ա����
		int K;
		K = L.length;        //�����Ա��Ԫ�ظ�����ֵ��K
		printf("���Ա���Ϊ%d\n",K);
		return OK;
	}
	else
		printf("���Ա����ڣ��޷��ж�\n");
	return OK;
}
