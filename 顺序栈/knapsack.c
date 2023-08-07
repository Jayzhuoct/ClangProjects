#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"
//背包问题
void knapsack(int w[],int T,int n)//w 为 n 件物品的体积， T 为背包的容量
{
    SqStack S;
    InitStack(&S);
    int k=0;
    do
    {
        while(T>0&&k<n)
        {
            if(T-w[k]>=0)
            {
                Push(&S,k);T-=w[k];
            }
            k++;
        }
        if(T==0)StackTraverse(S);
        Pop(&S,&k);
        T+=w[k];
        k++;
        if(k==n&&!StackEmpty(S))
        {
            Pop(&S,&k);T+=w[k];k++;
        }
    }while(k!=n);
}
