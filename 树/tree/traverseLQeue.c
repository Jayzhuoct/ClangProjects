#include <stdio.h>
#include <stdlib.h>
#include "List.h"
LinkQueue *traverseLQeue(LinkQueue *Q)
{
    QNode *q;
    q=(QNode *)malloc(sizeof(QNode));
    q=Q->front;
    do
    {
        printf("%c ",Q->front->data);
        Q->front=Q->front->next;
    }while(Q->front!=Q->rear->next);
    Q->front=q;
}
