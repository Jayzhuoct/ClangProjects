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
		for(i=0;i<8;i++)          //遍历八个方向
		{
			a=x+Move[i].x;
			b=y+Move[i].y;
			if(!maze[a][b]&&!t[a][b])
			{
				temp.x=a;temp.y=b;
				t[a][b]=maze[a][b]=1;     //用数组t,M记录这个位置已经走过了
				Push_SqStack(&elem,temp);
				path(a,b,elem);
				t[a][b]=maze[a][b]=0;     //回溯之后需要将这个位置清空，表示这条路没有走过
				Pop_SqStack(&elem);
			}
		}
	}
}
