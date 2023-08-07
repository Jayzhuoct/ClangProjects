#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
	int a[4],i,j,t;
	printf("输入4个整数: ");
	for(i=0;i<4;i++)
		scanf("%d",&a[i]);
	for(i=0;i<3;i++)	//冒泡排序法
		for(j=i+1;j<4;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	printf("按从小到大顺序： ");
	for(i=0;i<4;i++)
		printf("%d ",a[i]);
	return 0;
 }
