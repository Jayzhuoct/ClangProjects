//�����Ա�ĳһλ�ò���Ԫ��
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"
struct ListInsert_Sq(SqList *L,int i,ElemType e)
{
	ElemType *newbase;
	int *q,*p;
	if(i < 1 || i > L->length+1)         //�жϲ���λ�õ�indexֵ�Ƿ�Ϸ�
	    return ERROR;
	if(L->length >= L->listsize)
	{         //�����ǰ���Ա�洢�ռ����������ӷ���
		newbase = (ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)
		{                 //����洢�ռ����ʧ�ܣ���ִ���쳣�˳�
			printf("�洢�ռ����ʧ��\n");
			exit(OVERFLOW);
		}
		L->elem = newbase;               //�µĴ洢�ռ��ַ
		L->listsize += LISTINCREMENT;
	}
	q = &(L->elem[i-1]);                 //L.elem[index-1]Ϊ�����е����һ��Ԫ�أ�qΪҪ�����λ��
	for(p = &(L->elem[L->length - 1]);p >= q;--p)
    *(p+1) = *p;                    //Ҫ����λ���Լ�֮���λ�������
	*q = e;                             //��e���뵽��Ҫ�����λ��
	++L->length;                         //�����µ�Ԫ��֮�����1
	printf("Ԫ�ز���ɹ�\n");
	return OK;
}
