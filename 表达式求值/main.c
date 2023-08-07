#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 30
#include"header.h"
main()
{
	char zhong[N],hou[N];
	float answer;             //存储计算结果
	printf("**********20214075127李静**********\n");
	printf("\n**********表达式求值**********\n\n");
	printf("需要计算的中缀表达式为:  ");
	scanf("%s",zhong);
	while(strcmp(zhong,"#")!=0)   //当输入为"#"结束
	{
		transfer(zhong,hou);     //中缀转后缀
		printf("\n\n转化后的后缀表达式为：");
		printf("%s\n",hou);
		printf("\n**********计算结果**********\n");
		answer=Calculate_zhong(hou);
		printf("\n           %s",hou);
		printf(" = %f\n",answer);
		printf("\n**********计算完毕**********\n");
		printf("\n\n需要计算的中缀表达式为:  ");
	    scanf("%s",zhong);
	}
}
