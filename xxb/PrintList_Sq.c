#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"//��ӡ���Ա�
struct PrintList_Sq(SqList L)
{
	printf("��ǰ���Ա��Ԫ��Ϊ��");
	for(int K = 0;K < L.length;K++)      //������ǰ���Ա�
	    printf("  %d",L.elem[K]);
	printf("\n");                        //����
	return OK;
}
