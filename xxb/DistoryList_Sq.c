//�����Ա��������
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"
struct DistoryList_Sq(SqList *L)
{
	if(!L->elem)
    {
	  printf("����δ�������Ա����Ƚ������Ա�\n");
	  return ERROR;
	}
	free(L->elem);            //ʹ��free��������֮ǰ��̬������ڴ滹��ϵͳ
	L->elem = NULL;           //����elem��ֵΪNull
	L->length = 0;            //�����Ա��Ԫ�ظ�������Ϊ0
	L->listsize = 0;          //�����Ա�Ĵ洢��������Ϊ0
	printf("���Ա��Ѿ�����\n");
	return OK;
}
