#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"//�ж����Ա��Ƿ�Ϊ��
struct ListEmpty_Sq(SqList L)
{
	if(L.elem)
    {          //�ж����Ա��Ƿ�Ϊ�յ�ǰ�������Ա���ڣ�����Ԫ�ص�ַ��L.elem����ʱ˵�����Ա����
		if(L.length != 0)
		{               //������Ա���Ԫ��Ϊ0����L.length��ֵΪ0ʱ˵�����Ա��ǿձ�
		       printf("���Ա��ǿձ�\n");
		       return FALSE;
        }
			else
			   printf("���Ա��ǿձ�\n");
		return TRUE;
	}
	else
	printf("���Ա����ڣ��޷��ж�\n");
	return OK;
}
