void MultibaseOutput(long num,int B)
{
 LNode Stack;
 LinkStack S=&Stack;
 SElemType e;
 InitStack_L(S);
}
do
{
    Push_L(&S,num%B);
    num/=B;
    printf("%ld",num);
}
while(num!=0);
while(!StackEmpty_L(S))
{
    SElemType e;
    Pop_L(&S,&e);
    printf("%d",e);
}
