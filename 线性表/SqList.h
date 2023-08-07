#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OVERFLOW -1
#define TRUE 1
#define FALSE 0

typedef char ElemType;
typedef struct{
    ElemType *elem;
    int length;
    int listsize;
    }Sqlist;

void ClearList(Sqlist *L);
void DestroyList(Sqlist *L);
void InitList(Sqlist *L);
void input(Sqlist *L);
int listcompare(Sqlist La,Sqlist Lb);
void ListDelete(Sqlist *L,int Loc,ElemType *e);
int listempty(Sqlist *L);
void ListInsert(Sqlist *L,int loc,ElemType e);
int ListLength(Sqlist L);
void print(Sqlist L);

#endif // SQLIST_H_INCLUDED
