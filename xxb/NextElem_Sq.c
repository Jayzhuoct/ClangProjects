#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"//�����Ա�ĳһԪ�صĺ��
void NextElem_Sq(SqList L,int i)
{
	int K;
	if(L.elem)
    {          //�ж����Ա��Ƿ�Ϊ�յ�ǰ�������Ա���ڣ�����Ԫ�ص�ַ��L.elem����ʱ˵�����Ա����
	    if(i <= 1 || i > L.length - 1)              //�ж������iֵ�Ƿ�Ϸ�
        printf("������һ����Ч����\n");
		K = L.elem[i];        //����i��Ԫ�صĺ�һ��Ԫ�ظ�ֵ��K
		printf("��%d��λ�õ�ֱ�Ӻ��Ϊ��%d\n",i,K);
	}
	else
		printf("���Ա����ڣ��޷��ж�\n");
	return OK;
}
