//�����Ա��������
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"
struct ClearList_Sq(SqList *L)
{
	if(L->elem)
    {                            //������Ա����
	    L->length = 0;            //�����Ա��Ԫ�ظ�������Ϊ0
	    printf("���Ա�������\n");
	    return OK;
	}
	else
	printf("���Ա����ڣ��޷�����\n");
	return OK;
}
