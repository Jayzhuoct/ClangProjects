#include <stdio.h>
#include <stdlib.h>
#include "List.h"
LinkQueue *DeLQeue(LinkQueue *Q)
{
    QNode *q;
    q=(QNode *)malloc(sizeof(QNode));
    q=Q->front;
    printf("DDFSGAG\n");
    Q->front=Q->front->next;
    printf("DDFSGAG\n");
    free(q);
    return Q;
}
