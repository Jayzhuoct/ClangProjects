#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 30
#include"header.h"
void transfer(char *in,char *post)//中缀转后缀
{
	ST T;//栈
	int i,j,flag=0;    //flag=1说明是现在栈顶是数，用来判断是否出现连续两个运算符
	int count;     //记录每个数中小数点的个数，超过一个则表达式有误
	int right=0,left=0;     //left和right用来记录算式里面左右括号的个数
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
				 	if(in[i]=='.') //记录小数点出现的个数
				 		count++;
				}
				i--;
				if(count>1)
				{
				 	printf("\n表达式错误!!!!\n\n错误原因：数中有两个小数点\n");
				 	exit(0);
				}
				post[j]=' ';//用空格来分割两个数
				j++;
				flag=1;  //目前为数字，则flag为1
				break;
		case '(':if(flag)//如果括号前是数字，则表达式有误
				{
				 	printf("\n表达式错误!!!!\n\n错误原因：数字后直接跟括号\n");
				 	exit(0);
				}
				push(&T,in[i]);
				left++;//左括号个数加一
			    break;
		case ')':right++;   //右括号个数加一
				while(gettop(&T)!='(')
				{
					 post[j]=pop(&T);
					 j++;
				}
			     pop(&T);
				 break;
		case '+':
		case '-':if(!flag&&i!=0)//如果运算符前是运算符，则表达式有误
				{
				 	printf("\n表达式错误!!!!\n\n错误原因：有连续两个运算符之间没有数字\n");
				 	exit(0);
				}
				while(!isempty(&T)&&gettop(&T)!='(')
				{
					post[j]=pop(&T);
					j++;
				}
			    push(&T,in[i]);
			    flag=0;//目前为符号，所以flag为0
				break;
		case '*':
		case '/':if(!flag)//如果运算符前是运算符，则表达式有误
				{
				 	printf("\n表达式错误!!!!\n\n错误原因：有连续两个运算符之间没有数字\n");
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
		default:printf("\n表达式错误!!!!\n\n错误原因：输入非法字符，无法试别\n");
			    exit(0);
		}
	}
	if(left!=right)
	{
		printf("\n表达式错误!!!!\n\n错误原因：左右括号不匹配\n");
		exit(0);
	}
	while(!isempty(&T))
	{
		post[j]=pop(&T);
		j++;
	}
	post[j]='\0';
}
