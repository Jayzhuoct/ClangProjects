#include <stdio.h>
#include <stdlib.h>

int gongyue(int x,int y)
{
    int i,gy,min;
    min=x>y?y:x;
    for(i=1;i<=min;i++)
        if(x%i==0&&y%i==0)
    {
        gy=i;
    }
    return gy;
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf(" %d\n",gongyue(a,b));
    return 0;
}
