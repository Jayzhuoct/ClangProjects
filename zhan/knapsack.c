#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
void knapsack(int w[], int T, int n)
{
 SqStack S;
 InitStack_Sq(&S);
 int k=0;
 do
{
   while(T>0 && k<n)
{
   if(T-w[k]>=0)
{
    Push_Sq(&S,k); T-=w[k];
}
    k++;
}
    if (T==0) StackTraverse_Sq(S);
    Pop_Sq(&S,&k);
    T+=w[k];
    k++;
    if(k==n && !StackEmpty_Sq(S))
{
     Pop_Sq(&S,&k); T+=w[k]; k++;
}
}
while(k!=n);
}
