#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 30
#include"header.h"
float Calculate_zhong(char *post)//�����ֵ���ú�׺�����㣩

{
	int i,j,top=-1,flag;       //topΪջ������ʼֵΪ-1��flag�����ж������Ƿ����С����
	int len;                   //len��ʾ����С����ǰ�ĳ���
	float temp,aa[N];          //aa[N]������ű��ʽ�е����֣�tempΪ��ʱ����
	char ch[N];                //�Ȱ����ֵı��ʽ�浽ch[N]�У���ת��Ϊ���ִ浽aa[N]
	for(i=0,j;post[i]!='\0';i++)  //���˿�ʼ��ȡջ�ĺ�׺���ʽ������
	{
		if(post[i]>='0'&&post[i]<='9')//�����ǰΪ���֣��Ƚ����ִ浽ch�У���ת��Ϊfloat���Ͳ��浽aa��
		{
			flag=0; //��ʼΪ0
			j=0;  //������¼�ַ����ĳ���
			while(post[i]!=' ')//����һ���������ֵ��ַ����浽ch�У�ֱ�����ֽ���
			{
				if(post[i]=='.')//�ж��Ƿ���С���㣬�ֱ�����
					flag=1; //��С����
				ch[j]=post[i];//�����ִ��뵽ch[N]��
				i++;
				j++;
			}
			ch[j]='\0'; //�����������ʾ�ַ�����β
			if(flag)//��С��������������С����ǰ�ģ�����С�����ģ��ֿ�����
			{
				for(j=0;ch[j]!='.';j++);//���󳤶ȣ��ҵ�j��λ�ã���ô����Ϊj-1
					len=j-1;
				for(j=0,temp=0.;ch[j]!='.';j++)  //����С����ǰ�ĺ�
					temp+=(ch[j]-'0')*pow(10,len-j);
				for(j++,len++;ch[j]!='\0';j++)   //����С����ǰ�ĺ�
					temp+=(ch[j]-'0')*pow(10,len-j);
			}
			else//ûС��������
			{
				for(j=0;ch[j]!='\0';j++);//�����Ӧ�ĳ���
					len=j-1;
				for(j=0,temp=0.;ch[j]!='\0';j++)
					temp+=(ch[j]-'0')*pow(10,len-j);
			}
			top++;
			aa[top]=temp;//temp��ջ������������ֵĴ���ͽ�����
		}
		else      //������������ջ����������ջ������������������������ջ����������
		{
			switch(post[i])  //���ݲ�ͬ����������������
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
	return aa[top];//���յļ���������ջ��
}
