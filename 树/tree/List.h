#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef char QElemType;
typedef struct QNode
{ //队列结点
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

LinkQueue *InitLQeue(LinkQueue *Q);
LinkQueue *EnLQeue(LinkQueue *Q,QElemType e);
LinkQueue *DestoryLQeue(LinkQueue *Q);
LinkQueue *DeLQeue(LinkQueue *Q);
LinkQueue *traverseLQeue(LinkQueue *Q);
LinkQueue *CreatLQueue(LinkQueue *Q);
LinkQueue *EmptyLQueue(LinkQueue *Q);
char GetLQueue(LinkQueue *Q);

#endif // LIST_H_INCLUDED
