#include <stdio.h>
#include <stdlib.h>
#include "List.h"
LinkQueue *DestoryLQeue(LinkQueue *Q)
{
    while(Q->front)
    {
        Q->rear=Q->front->next;
        free(Q->front);
        Q->front=Q->rear;
    }
    return Q;
}
