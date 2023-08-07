#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"
//��������
void knapsack(int w[],int T,int n)//w Ϊ n ����Ʒ������� T Ϊ����������
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
