#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
	int a[4],i,j,t;
	printf("����4������: ");
	for(i=0;i<4;i++)
		scanf("%d",&a[i]);
	for(i=0;i<3;i++)	//ð������
		for(j=i+1;j<4;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	printf("����С����˳�� ");
	for(i=0;i<4;i++)
		printf("%d ",a[i]);
	return 0;
 }
