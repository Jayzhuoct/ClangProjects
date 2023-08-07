#include <stdio.h>
#include <stdlib.h>
#include "List.h"
LinkQueue *EnLQeue(LinkQueue *Q,QElemType e)
{
    QNode *p;
    p=(QNode*)malloc(sizeof(QNode));
    p->data=e;
    p->next=NULL;
    if(Q->front==NULL)
    {
        Q->front=p;
        Q->rear=p;
    }
    else
    {
        Q->rear->next=p;
        Q->rear=Q->rear->next;
    }
    return Q;

}
