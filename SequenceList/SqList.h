#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED
typedef char ElemType;
typedef struct SqList
{
    ElemType *elem;
    int length;
    int listsize;
}SqList;
SqList InitList(SqList L);
#endif // SQLIST_H_INCLUDED
