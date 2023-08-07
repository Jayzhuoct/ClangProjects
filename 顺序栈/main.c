#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"
int main()
{
    SqStack S;
    int b[10];
    int m;

    printf("------inittiative(初始化)------\n");
    InitStack(&S);
    int i;

    printf("------push(入栈)------\n");
    for(i=0;i<10;i++)
    {
        Push(&S,i+2);
    }

    printf("------Length(栈长)------\n");
    printf("StackLength = %d\n",StackLength(S));

    printf("------Traverse(遍历栈)------\n");
    StackTraverse(S);

    printf("------GetTop(得到栈顶元素)------\n");
    GetTop(S,&m);
    printf("m= %d \n",m);

    printf("------Pop(出栈)------\n");
    for(i=0;i<10;i++)
    {
        Pop(&S,&b[i]);
        printf("%d",b[i]);
    }
    printf("\n");
    printf("StackLength = %d \n\n",StackLength(S));
    DestroyStack(&S);
    int w[6]={1,8,4,3,5,2};
    knapsack(w,10,6);

    return 0;
}
