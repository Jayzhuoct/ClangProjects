#include <stdio.h>
#include <stdlib.h>
#include "LNode.h"
//������������
void MultibaseOutput(long num,int B)
{
    LNode Stack;
    LinkStack S=&Stack;
    SElemType e;
    InitStack(&S);
    do{
        Push(&S,num%B);
        num/=B;
    }while(num!=0);
    while(!StackEmpty(S))
    {
     Pop(&S,&e);
    }

}
