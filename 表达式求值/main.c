#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 30
#include"header.h"
main()
{
	char zhong[N],hou[N];
	float answer;             //�洢������
	printf("**********20214075127�**********\n");
	printf("\n**********���ʽ��ֵ**********\n\n");
	printf("��Ҫ�������׺���ʽΪ:  ");
	scanf("%s",zhong);
	while(strcmp(zhong,"#")!=0)   //������Ϊ"#"����
	{
		transfer(zhong,hou);     //��׺ת��׺
		printf("\n\nת����ĺ�׺���ʽΪ��");
		printf("%s\n",hou);
		printf("\n**********������**********\n");
		answer=Calculate_zhong(hou);
		printf("\n           %s",hou);
		printf(" = %f\n",answer);
		printf("\n**********�������**********\n");
		printf("\n\n��Ҫ�������׺���ʽΪ:  ");
	    scanf("%s",zhong);
	}
}
