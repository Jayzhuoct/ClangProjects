#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 30
#include"header.h"
void transfer(char *in,char *post)//��׺ת��׺
{
	ST T;//ջ
	int i,j,flag=0;    //flag=1˵��������ջ�������������ж��Ƿ�����������������
	int count;     //��¼ÿ������С����ĸ���������һ������ʽ����
	int right=0,left=0;     //left��right������¼��ʽ�����������ŵĸ���
	T.top=-1;
	for(i=0,j=0;in[i]!='\0';i++)
	{
		switch(in[i])
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':for(count=0;(in[i]<='9'&&in[i]>='0')||in[i]=='.';i++,j++)
				{
				 	post[j]=in[i];
				 	if(in[i]=='.') //��¼С������ֵĸ���
				 		count++;
				}
				i--;
				if(count>1)
				{
				 	printf("\n���ʽ����!!!!\n\n����ԭ������������С����\n");
				 	exit(0);
				}
				post[j]=' ';//�ÿո����ָ�������
				j++;
				flag=1;  //ĿǰΪ���֣���flagΪ1
				break;
		case '(':if(flag)//�������ǰ�����֣�����ʽ����
				{
				 	printf("\n���ʽ����!!!!\n\n����ԭ�����ֺ�ֱ�Ӹ�����\n");
				 	exit(0);
				}
				push(&T,in[i]);
				left++;//�����Ÿ�����һ
			    break;
		case ')':right++;   //�����Ÿ�����һ
				while(gettop(&T)!='(')
				{
					 post[j]=pop(&T);
					 j++;
				}
			     pop(&T);
				 break;
		case '+':
		case '-':if(!flag&&i!=0)//��������ǰ�������������ʽ����
				{
				 	printf("\n���ʽ����!!!!\n\n����ԭ�����������������֮��û������\n");
				 	exit(0);
				}
				while(!isempty(&T)&&gettop(&T)!='(')
				{
					post[j]=pop(&T);
					j++;
				}
			    push(&T,in[i]);
			    flag=0;//ĿǰΪ���ţ�����flagΪ0
				break;
		case '*':
		case '/':if(!flag)//��������ǰ�������������ʽ����
				{
				 	printf("\n���ʽ����!!!!\n\n����ԭ�����������������֮��û������\n");
				 	exit(0);
				}
				while(!isempty(&T)&&(gettop(&T)=='/'||gettop(&T)=='*'))
				{
					 post[j]=pop(&T);
					 j++;
				}
			    push(&T,in[i]);
			    flag=0;
				break;
		default:printf("\n���ʽ����!!!!\n\n����ԭ������Ƿ��ַ����޷��Ա�\n");
			    exit(0);
		}
	}
	if(left!=right)
	{
		printf("\n���ʽ����!!!!\n\n����ԭ���������Ų�ƥ��\n");
		exit(0);
	}
	while(!isempty(&T))
	{
		post[j]=pop(&T);
		j++;
	}
	post[j]='\0';
}
