#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
   float average(float array[10]);
   float score[10],aver;
   int i;
   printf("������ɼ���\n");
   for(i=0;i<=10;i++)
    scanf("%f",&score[i]);
   printf("\n");
   aver=average(score);
   printf("ƽ���ɼ��ǣ�%5.2f\n",aver);
   return 0;
}
   float average(float array[10])
{
    int i;
    float aver,sum=array[0];
    for(i=1;i<=10;i++)
        sum=sum+array[i];
    aver=sum/10;
    return(aver);
}


