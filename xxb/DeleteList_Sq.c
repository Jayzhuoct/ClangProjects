//ɾ�����Ա�ĳһλ�õ�Ԫ��
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"
struct DeleteList_Sq(SqList *L,int i)
{
	int *p,*q;
	if(i < 1 || i > L->length)
    {            //���Ҫɾ����λ�ò��Ϸ�
		printf("������һ����Ч����\n");
		return ERROR;
	}
	p = &(L->elem[i - 1]);                 //pΪ��ɾ��Ԫ�ص�λ��
	q = L->elem + L->length - 1;            //����βԪ�ص�λ�ø�ֵ��q
	for(++p;p <= q;p++)
    *(p - 1) = *p;                    //��ɾ����Ԫ��֮���Ԫ��ȫ������
	--L->length;                           //����1
	printf("��%d��Ԫ��ɾ���ɹ�\n",i);
	return OK;
}
