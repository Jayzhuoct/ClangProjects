#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "SqList.h"

int main()
{
	SetConsoleTitle("���Ա��˳��ʵ��");
	SqList L;
	int choose,index,e;
	while(1){
		printf("*****************************************\n");
		printf("*                                       *\n");
		printf("*  ���Ա��˳���ʾ��ʵ�֣�             *\n");
		printf("*                                       *\n");
		printf("*    1.  ����һ���յ����Ա�             *\n");
		printf("*    2.  �����Ա���и�ֵ               *\n");
		printf("*    3.  �����Ա��������               *\n");
		printf("*    4.  �����Ա��������               *\n");
		printf("*    5.  �ж����Ա��Ƿ�Ϊ��             *\n");
		printf("*    6.  ��ȡ���Ա�ĳ���               *\n");
		printf("*    7.  ��ȡ���Ա�ĳһλ�ö�Ӧ��Ԫ��   *\n");
		printf("*    8.  �����Ա�ĳһλ�ò���Ԫ��       *\n");
		printf("*    9.  ɾ�����Ա�ĳһλ�õ�Ԫ��       *\n");
		printf("*    10. �����Ա�ĳһԪ�ص�ǰ��         *\n");
		printf("*    11. �����Ա�ĳһԪ�صĺ��         *\n");
		printf("*    12. ��ӡ���Ա�                     *\n");
		printf("*    13. �˳�                           *\n");
		printf("*                                       *\n");
		printf("*****************************************\n");
		printf("����������ѡ��");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:InitList_Sq(L);break;
			case 2:ValueList_Sq(L);break;
			case 3:DistoryList_Sq(L);break;
			case 4:ClearList_Sq(L);break;
			case 5:ListEmpty_Sq(L);break;
			case 6:ListLength_Sq(L);break;
			case 7:
            {
				printf("������Ҫ��ȡԪ�ص�λ�ã�");
				scanf("%d",&index);
				GetElem_Sq(L,index);
			}
			break;
			case 8:
            {
				printf("������Ҫ����Ԫ�ص�λ�ã�");
				scanf("%d",&index);
				printf("������Ҫ�����Ԫ�أ�");
				scanf("%d",&e);
				ListInsert_Sq(L,index,e);
			}
			break;
			case 9:
            {
				printf("������Ҫɾ��Ԫ�ص�λ�ã�");
				scanf("%d",&index);
				DeleteList_Sq(L,index);
			}
			break;
			case 10:
            {
				printf("��������Ҫ������һ��Ԫ�ص�ǰ����");
				scanf("%d",&index);
				PriorElem_Sq(L,index);
			}
			break;
			case 11:{
				printf("��������Ҫ������һ��Ԫ�صĺ�̣�");
				scanf("%d",&index);
				NextElem_Sq(L,index);
			}
			break;
			case 12:PrintList_Sq(L);break;
			case 13:exit(0);
		}
	}
	return 0;
}
