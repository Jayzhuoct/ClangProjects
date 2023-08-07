#ifndef SQSTACK_H_INCLUDED
#define SQSTACK_H_INCLUDED
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OVERFLOW -1
//顺序栈结构体
typedef int SElemType;
typedef struct SqStack
{
    SElemType*elem;
    int top;
    int stacksize;
    int increment;
}SqStack;
void incrementStacksize(SqStack *s);
void InitStack(SqStack *S);
void GetTop(SqStack S,SElemType *e);
void Push(SqStack *S,SElemType e);
void Pop(SqStack *S,SElemType *e);
void DestroyStack(SqStack *S);
void ClearStack(SqStack *S);
int StackEmpty(SqStack S);
int StackLength(SqStack S);
void StackTraverse(SqStack S);
void knapsack(int w[],int T,int n);

#endif // SQSTACK_H_INCLUDED
