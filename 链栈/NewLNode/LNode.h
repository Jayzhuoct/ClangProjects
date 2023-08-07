#ifndef LNODE_H_INCLUDED
#define LNODE_H_INCLUDED
#define OVERFLOW -1;
typedef int SElemType;
typedef struct LNode
{
    SElemType data;
    struct LNode *next;
}LNode;
typedef LNode *LinkStack;
void InitStack(LinkStack *S);
void Pop(LinkStack *S,SElemType *e);
void Push(LinkStack *S,SElemType e);
int StackEmpty(LinkStack S);
void StackTraverse(LinkStack S);
void MultibaseOutput(long num,int B);
#endif // LNODE_H_INCLUDED
