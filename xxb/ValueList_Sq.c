#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"//�����Ա���и�ֵ
struct ValueList_Sq(SqList *L)
{
	int i,j;
	printf("���������Ա�Ԫ�صĸ�����");
	scanf("%d",&i);
	if(i > L.listsize)                     //�����Ҫ�����Ԫ�ظ��������ڴ��Сʱ
	{
		while(1)             //һֱ�����¿ռ䣬ֱ�����ٵĿռ������Ҫ�Ŀռ�Ϊֹ
		{
			if(i > L.listsize){
				L->elem = (ElemType *)realloc(L->elem,LISTINCREMENT * sizeof(ElemType));
				L->listsize += LISTINCREMENT;
        /*realloc()���������·���ռ�
		           ������ԭ�ռ��ַ������ռ��С
		           ���أ�1.�ɹ����¿ռ��ַ(��������һ����ֵ)
		                 2.ʧ�ܣ�Null*/
			}
			else
			break;
		}
	}
	for(j = 0;j < i;j++){
		printf("�������%d��Ԫ�أ�",j + 1);
	    scanf("%d",&L.elem[j]);
	}
	L.length = i;          //��ֵ��ɺ��޸Ĳ��������Ա�ĳ���
	printf("��ֵ�ɹ�\n");
	return OK;
}
