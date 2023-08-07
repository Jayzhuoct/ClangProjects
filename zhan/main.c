#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
int main()
{
SqStack S;
int b[10];
int m;
printf("--------inittiative_stack(初始化)-------- \n");
InitStack_Sq(&S);
int i;
printf("--------push_stack(入栈)---------------- \n");
for(i=0;i<10;i++)
{
Push_Sq(&S,i+2);
}
printf("--------stack_Length(栈长)----------------\n");
printf("StackLength = %d\n",StackLength_Sq(S));
printf("--------Traverse_stack(遍历栈)------------\n");
StackTraverse_Sq(S);
printf("--------GetTop_stack(得到栈顶元素)--------\n");
GetTop_Sq(S,&m);
printf("m=%d\n",m);
printf("--------Pop_stack(出栈)-------------------\n");
for(i=0;i<10;i++)
{
Pop_Sq(&S,&b[i]);
printf("%d ",b[i]);
}
printf("\n");
printf("StackLength = %d\n",StackLength_Sq(S));
DestroyStack(&S);
int w[6]={1,8,4,3,5,2};
knapsack(w,10,6);
return 0;
}
