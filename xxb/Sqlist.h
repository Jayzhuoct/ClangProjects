#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED
#define TRUE     1     //�����г���TRUE�൱�ڳ�����1
#define FALSE    0     //����FALSE�൱�ڳ�����0
#define OK       1     //����OK�൱�ڳ�����1
#define ERROR    0     //����ERROR�൱�ڳ�����0
#define INFEASIBLE    -1
#define OVERFLOW      -2
#define LIST_INIT_SIZE    100     //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT     10      //���Ա�洢�ռ�ķ�������
typedef int ElemType;
typedef struct
{
	ElemType *elem;          //�洢�ռ�Ļ�ַ
	int length;              //��ǰ���Ա�ĳ���
	int listsize;            //��ǰ���Ա�Ĵ洢����
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
