#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#define m 6
#define n 8
#define STACK_INIT_SIZE 100

void path(int x,int y,SqStack elem)
{
	int i,a,b;
	SElemType temp;
	if(x==6&&y==8)
	{
		sum++;
		Print(sum,elem);
	}
	else
	{
		for(i=0;i<8;i++)          //�����˸�����
		{
			a=x+Move[i].x;
			b=y+Move[i].y;
			if(!maze[a][b]&&!t[a][b])
			{
				temp.x=a;temp.y=b;
				t[a][b]=maze[a][b]=1;     //������t,M��¼���λ���Ѿ��߹���
				Push_SqStack(&elem,temp);
				path(a,b,elem);
				t[a][b]=maze[a][b]=0;     //����֮����Ҫ�����λ����գ���ʾ����·û���߹�
				Pop_SqStack(&elem);
			}
		}
	}
}
