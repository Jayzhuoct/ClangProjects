#ifndef LNODE_H_INCLUDED
#define LNODE_H_INCLUDED
#define OVERFLOW -1
#define TRUE 1
#define FALSE 0
typedef int ElemType;
struct Lnode{
    ElemType data;
    struct Lnode *next;
    };
typedef struct Lnode LNode;
typedef struct Lnode *LinkList;


LinkList InitList(LinkList L);
void DestroyList(LinkList L);

#endif // LNODE_H_INCLUDED
