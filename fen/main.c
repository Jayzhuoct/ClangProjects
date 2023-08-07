#include <stdio.h>
#include <stdlib.h>
float Max=0,Min=0;
int main()
{
    float average(float array[],int n);
    float ave,score[10];
    int i;
    printf("请输入10个成绩：\n");
    for(i=0;i<10;i++)
    scanf("%f",&score[i]);
    ave=average(score,10);
    printf("max=%6.2f\nmin=%6.2f\naverage=%6.2f\n",Max,Min,ave);
    return 0;
}
float average(float array[],int n)
{
    int i;
    float aver,sum=array[0];
    Max=Min=array[0];
    for(i=1;i<n;i++)
    {
        if(array[i]>Max)Max=array[i];
        else if(array[i]<Min)Min=array[i];
        sum=sum+array[i];
    }
    aver=sum/n;
    return(aver);
}
//愿你风月都好看，爱恨皆浪漫。你是落日弥漫的橘，亦是天边透亮的星。晚是世界的晚，安是给你的安。
