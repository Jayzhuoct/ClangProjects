#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED
#define TRUE     1     //代码中出现TRUE相当于出现了1
#define FALSE    0     //出现FALSE相当于出现了0
#define OK       1     //出现OK相当于出现了1
#define ERROR    0     //出现ERROR相当于出现了0
#define INFEASIBLE    -1
#define OVERFLOW      -2
#define LIST_INIT_SIZE    100     //线性表存储空间的初始分配量
#define LISTINCREMENT     10      //线性表存储空间的分配增量
typedef int ElemType;
typedef struct
{
	ElemType *elem;          //存储空间的基址
	int length;              //当前线性表的长度
	int listsize;            //当前线性表的存储容量
}
struct InitList_Sq(SqList *L);
struct ValueList_Sq(SqList *L);
struct DistoryList_Sq(SqList *L);
struct ClearList_Sq(SqList *L);
struct ListEmpty_Sq(SqList L);
struct ListLength_Sq(SqList L);
struct GetElem_Sq(SqList L,int index);
struct ListInsert_Sq(SqList *L,int i,ElemType e);
struct PrintList_Sq(SqList L);
struct DeleteList_Sq(SqList *L,int i);
struct PriorElem_Sq(SqList *L,int i);
struct NextElem_Sq(SqList L,int i);

#endif // SQLIST_H_INCLUDED
