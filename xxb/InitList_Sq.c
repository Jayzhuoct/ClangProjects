//����һ���յ����Ա�
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"
struct InitList_Sq(SqList *L)
{
	L->elem=(ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));      //L.elemΪ��Ԫ�صĵ�ַ
	if(!L->elem)
    {            //����洢�ռ����ʧ�ܣ�L.elemΪNULL
	printf("�洢�ռ����ʧ��\n");
	exit(OVERFLOW);
	}
	L->length = 0;            //��ǰ���Ա�Ϊ�ձ������Ա���Ϊ0
	L->listsize = LIST_INIT_SIZE;           //�����Ա�����ʼ����
	printf("һ���յ����Ա��Ѿ������ɹ�\n");      //��������Ա����ɹ�����ʾ��Ϣ
	return OK;
}
