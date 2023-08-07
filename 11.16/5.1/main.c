#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a[10];
   int i,j,t;
   printf("请输入班级c语言成绩\n");
   for(i=0;i<10;i++)
   scanf("%d",&a[i]);
   printf("\n");
   for(j=0;j<9;j++)
   for(i=0;i<9-j;i++)
     if(a[i]>a[i+1])
    {
    t=a[i];
    a[i]=a[i+1];
    a[i+1]=t;
    }
    printf("成绩按高到低的顺序是\n");
   for(i=0;i<10;i++)
     printf("%d ",a[i]);
   printf("\n");
   printf("最高成绩是%d\n",a[0]);
   printf("最低成绩是%d\n",a[9]);
   return 0;
}
