#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef char TElemType;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTree;
typedef struct
{
    BiTree *ptr;
    int task;
}ElemType;


BiTree *CreatBiTree(BiTree *T);
void EmptyBiTree(BiTree *T);
BiTree *InitBiTree(BiTree *T);
void PreOrderTraserve(BiTree *T);
void InOrderTraverse(BiTree *T);
void PostOrderTraverse(BiTree *T);
int BiTreeDepth(BiTree *T,int h,int depth);
BiTree *GetTreeNode(TElemType item,BiTree *lptr,BiTree *rptr);
BiTree *CopyTree(BiTree *T);


#endif // LIST_H_INCLUDED

