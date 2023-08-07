#include <stdio.h>
#include <stdlib.h>
#include "List.h"
LinkQueue *CreatLQueue(LinkQueue *Q)
{
    printf("please input the number of LQueue\n");
    int a;
    scanf("%d",&a);
    getchar();
    char c;
    c=getchar();
    Q=EnLQeue(Q,c);
    for(int i=1;i<a;i++)
    {
        getchar();
        c=getchar();
        Q=EnLQeue(Q,c);
    }
    return Q;
}
