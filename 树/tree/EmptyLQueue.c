#include <stdio.h>
#include <stdlib.h>
#include "List.h"

LinkQueue *EmptyLQueue(LinkQueue *Q)
{
    if(Q->front==Q->rear)
    {
        printf("LQueue is empty\n");
    }
    else
    {
        printf("LQueue is not empty\n");
    }
}
