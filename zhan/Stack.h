#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define STACK_INIT_SIZE_100
#define OVERFLOW -1
typedef int SElemType;
typedef struct SqStack
   {
    SElemType*elem;
    int top;
    int stacksize;
    int increment;
   }SqStack;
#endif // STACK_H_INCLUDED
