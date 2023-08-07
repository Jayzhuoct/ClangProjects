#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OVERFLOW -1
#define TRUE 1
#define FALSE 0
typedef char ElemType
typedef struct
{
    ElemType *elem
    int length
    int listsize
}Sqlist
