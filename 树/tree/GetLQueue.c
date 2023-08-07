#include <stdio.h>
#include <stdlib.h>
#include "List.h"

char GetLQueue(LinkQueue *Q)
{
    char c;
    if(Q->front!=Q->rear)
    {
        c=Q->front->data;
    }
    else
    {
        printf("error\n");
    }
    return c;
}
