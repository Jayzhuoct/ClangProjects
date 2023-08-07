#include <stdio.h>
#include <stdlib.h>
#include "List.h"
LinkQueue *InitLQeue(LinkQueue *Q)
{
    Q=(LinkQueue *)malloc(sizeof(LinkQueue));
    Q->front=NULL;
    Q->rear=NULL;
    return Q;
}
