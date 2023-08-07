#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 30
#include"header.h"
float Calculate_zhong(char *post)//计算的值（用后缀来计算）

{
	int i,j,top=-1,flag;       //top为栈顶，初始值为-1，flag用来判断数字是否存在小数点
	int len;                   //len表示数字小数点前的长度
	float temp,aa[N];          //aa[N]用来存放表达式中的数字，temp为临时变量
	char ch[N];                //先把数字的表达式存到ch[N]中，再转化为数字存到aa[N]
	for(i=0,j;post[i]!='\0';i++)  //依此开始读取栈的后缀表达式的内容
	{
		if(post[i]>='0'&&post[i]<='9')//如果当前为数字，先将数字存到ch中，再转化为float类型并存到aa中
		{
			flag=0; //初始为0
			j=0;  //用来记录字符串的长度
			while(post[i]!=' ')//将这一串代表数字的字符串存到ch中，直到数字结束
			{
				if(post[i]=='.')//判断是否有小数点，分别讨论
					flag=1; //有小数点
				ch[j]=post[i];//把数字存入到ch[N]中
				i++;
				j++;
			}
			ch[j]='\0'; //加上这个，表示字符串结尾
			if(flag)//有小数点的情况，先算小数点前的，再算小数点后的，分开计算
			{
				for(j=0;ch[j]!='.';j++);//先求长度，找到j的位置，那么长度为j-1
					len=j-1;
				for(j=0,temp=0.;ch[j]!='.';j++)  //计算小数点前的和
					temp+=(ch[j]-'0')*pow(10,len-j);
				for(j++,len++;ch[j]!='\0';j++)   //计算小数点前的和
					temp+=(ch[j]-'0')*pow(10,len-j);
			}
			else//没小数点的情况
			{
				for(j=0;ch[j]!='\0';j++);//求出相应的长度
					len=j-1;
				for(j=0,temp=0.;ch[j]!='\0';j++)
					temp+=(ch[j]-'0')*pow(10,len-j);
			}
			top++;
			aa[top]=temp;//temp入栈，到这里对数字的处理就结束了
		}
		else      //如果是运算符，栈顶两个数出栈，并把这两个数的运算结果入栈！！！！！
		{
			switch(post[i])  //根据不同的运算结果进行运算
			{
				case'+':temp=aa[top];
						top--;
						temp+=aa[top];
						aa[top]=temp;
						break;
				case'-':temp=aa[top];
						top--;
						temp=aa[top]-temp;
						aa[top]=temp;
						break;
				case'*':temp=aa[top];
						top--;
						temp=temp*aa[top];
						aa[top]=temp;
						break;
				case'/':temp=aa[top];
						top--;
						temp=aa[top]/temp;
						aa[top]=temp;
			}
		}
	}
	return aa[top];//最终的计算结果就在栈顶
}
