#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

int main()
{
    SqList La;
    La=InitList(La);
    return 0;
}

//头文件
#include<iostream.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
//常量定义
const int LIST_INIT_SIZE=100; //链表初始容量
const int LISTINCREMENT=10; //扩容时的增量
const int OVERFLOW=-1;
typedef char ElemType;
struct SqList2
{
 ElemType *elem; //存储元素的基地址
 int length; //链表长度
 int listsize; //链表容量
};
//线性表的初始化函数
void InitList_Sq(SqList &L) //L 为待初始化顺序表的引用
{
 L.elem=new ElemType[LIST_INIT_SIZE]; //分配内容空间
 if(!L.elem) exit(OVERFLOW); //判断分配是否成功
 L.length=0; L.listsize= LIST_INIT_SIZE; //初始化长度与容量
}
//线性表的销毁函数
void DestroyList_Sq(SqList &L) //L 为待销毁顺序表的引用
{
 free() [] L.elem; //释放内存空间
 L.listsize=0; L.length=0; //长度与容量清空
}
//线性表的插入操作
void ListInsert_Sq(SqList &L, int I, ElemType e) //L 为待插入线性表，I 为插入
 //位置，e 为待插入元素值
{
 ElemType *newbase, *q;
if(I<1 || I>L.length+1) cout<<"error"; //判断 I 的合理性
 if(L.length >= L.listsize) //如果条件成立，则需要扩容，
 {
 newbase=(ElemType *) realloc(L.elem,
 (L.listsize+LISTINCREMENT)*sizeof(ElemType));
 if(!newbase) exit(OVERFLOW);
 L.elem=newbase; L.listsize+=LISTINCREMENT;
 }
 q=&(L.elem[I-1]); //记录插入地址
 for(ElemType *p=&(L.elem[L.length-1]); p>=q; --p)
 *(p+1)=*p; //向前移动元素
 *q=e; ++L.length; //插入元素，并更新表长
}
//线性表的删除操作
void ListDelete_Sq(SqList &L, int I, ElemType &e) //L 为待删除线性表，I 为删除
{ //位置，通过 e 带回删除元素值
 if(I<1 || I>L.length) return ; //判断 I 的合理性
 ElemType *p=&(L.elem[I-1]); e=*p; //记录删除元素
 ElemType *q=L.elem+L.length-1; //记录线性表的表尾地址
 for(++p; p<=q; ++p) *(p-1)=*p; //元素向前移动
 -- L.length; //更新表长
}
//线性表的清空操作3
void ClearList_Sq(SqList &L){ L.length=0;} //L 为待清空线性表
//线性表的判空操作
int ListEmpty_Sq(SqList L)
{
if(L.length==0) return 1; //若长度为 0 则线性表为空
else return 0;
}
//求表长度
int ListLength_Sq(SqList L){ return L.length; }
//两个线性表的字典序比较
int compare(SqList La, SqList Lb) //La 和 Lb 分别表示两个待比较线性表
{
 int j=1; //控制线性表中元素的位置
 while(j<=La.length && j<=Lb.length) //当两个表都没到表尾时继续
 {
 if(La.elem[j]<Lb.elem[j]) return -1; //比较对应元素，得到相应结果
 else if(La.elem[j]>Lb.elem[j]) return 1;
 else j++;
 } //结束条件可能是已经比较出结果，则停止，若没有，则继续
 if(La.length==Lb.length) return 0; //当两个表都到了表尾时，相等
 else if(La.length<Lb.length)return -1; //比较两个表的长度，长度大者为大
 else return 1;
}
void main()
{
SqList La,Lb; //声明两个线性表
char ch1[80],ch2[80]; //接收从键盘输入的字符数组
 InitList_Sq(La); InitList_Sq(Lb); //初始化两个线性表
cout<<"please input the first string:"<<endl;
cin.getline(ch1,80,'\n'); //从键盘输入字符，最长 80 个，以回车为结束
 //标识将接收到的第一个字符串存储在表 La 中
for(int i=0;i<strlen(ch1);i++) ListInsert_Sq(La, i+1, *(ch1+i));
 cout<<"please input the second string:"<<endl;
cin.getline(ch2,80,'\n'); //从键盘输入字符，最长 80 个，以回车为结束标识
 //将接收到的第一个字符串存储在表 Lb 中
for(i=0;i<strlen(ch2);i++) ListInsert_Sq(Lb, i+1, *(ch2+i));
 cout<<"the result ot comparation:"<<endl;
cout<<compare(La,Lb)<<endl; //输出比较结果
}

//头文件
#include<iostream.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef int ElemType;
const int OVERFLOW=-1;5
struct Lnode{ //链表中的结点
 ElemType data; //数据域
 struct Lnode *next; //指针域
};
typedef Lnode * LinkList; //定义链表抽象数据类型
//链表的初始化
void InitList_L(LinkList &L) //L 为待初始化的链表
{
 L=new Lnode[1]; //分配头结点的空间
 if(!L) exit(OVERFLOW);
 L->next=NULL; //尾部指针赋值为空
}
//销毁链表
void DestroyList_L(LinkList &L)
{
 Lnode *p=L; //设立临时指针
p=p->next; //指向第一个元素
 while(p) //当 p 非空时进行
{
L->next=p->next; //将头指针后移
delete p; //释放临时的 p 的空间
p=L->next; //重新指向第一个元素
}
}
//取元素操作
void GetElem_L(LinkList L, int I, ElemType &e) //L 为相应的链表，I 为取元素的
 //位置，通过 e 带回取出的元素值
{
 Lnode *p=L->next; //令 p 指向第一个元素
int j=1;
 while (p && j<I) { p=p->next; ++j; } //定位取元素的位置
 if(!p || j>I) return; //若没找到位置，则结束
 e=p->data; //带回要找的值
}
//求链表的长度
int ListLength_L(LinkList L)
{
 Lnode *p=L->next;
int k=0;
 while(p) //从第一个元素开始计数
 {
 k++; p=p->next;
 }
 return k;
}
//定位元素6
Lnode *LocateElem_L(LinkList L, ElemType e) //e 为要查找的元素
{
 Lnode *p=L;
 while(p && p->data!=e)p=p->next; //依次查找的过程
 return p; //返回查找的结果，如空表示没找到
}
//插入元素
void ListInsert_L(LinkList &L, int I, ElemType e) //在链表 L 中第 I 个位置插入元素 e
{
 Lnode *p=L;
int j=0;
 while(p && j<I-1){ p=p->next ;++j;} //查找插入位置
 if(!p || j>I-1) cout<<"ERROR";
 Lnode *s=new Lnode[1]; //生成结点
 s->data=e; s->next=p->next; p->next=s; //结点入链
}
//链表删除
void ListDelete_L(LinkList &L, int I, ElemType &e) //删除链表 L 中第 I 个元素，
 //并利用 e 带回。
{
 Lnode *p=L;
int j=0;
 while(p && j<I-1){p=p->next; ++j;} //查找要删除元素的位置
 if(!p || j>I-1) cout<<"ERROR";
 Lnode *q=p->next; p->next=q->next; e=q->data; //前驱与后续链接
delete q; //释放空间
}
//遍历链表
void LinkListTraverse(LinkList L)
{
Lnode *p=L->next;
while(p) //依次输出链表中的元素
{
cout<<p->data<<" ";
p=p->next;
}
cout<<endl;
}
//2、逆序创建链表
//以逆序的方式创建链表，即最先输入的是最后一个元素，此链表当中包含 n 个元素。
void CreateList_L(LinkList &L, int n)
{
 for (int I=n; I>0;--I)
 {7
 Lnode *p=new Lnode; //生成结点空间
 cin>>p->data;
 p->next=L->next; L->next=p; //插入链首位置
 }
}
//3、逆置链表
//从链表中删除链首元素，按逆序创建的方法插入到另一个链表中，达到逆置链表的目的。
void InvertLinkedList(LinkList &L)
{
 Lnode *p=L->next, *s,*q=NULL;
 while(p)
 { //s 为原链表的首元素，依次将 s 插入新链首，从而达到逆置
 s=p; p=p->next; s->next=q; q=s;
 }
L->next=s;
}
void main()
{
LinkList L;
InitList_L(L);
 cout<<"please input five element:"<<endl;
CreateList_L(L,5);
ListInsert_L(L, 3, 100);
 cout<<"the list after insert 100 to it :"<<endl;
LinkListTraverse(L);
 ElemType e;
 cout<<"the list after delete the position 3 : "<<endl;
ListDelete_L(L, 3, e);
LinkListTraverse(L);
}

#include<iostream.h>
typedef struct polyitem //链表中结点的数据域
{
int coef; //系数
int exp; //指数
}ElemType; 8
const int OVERFLOW=-1;
struct Lnode{ //链表中结点类型
 ElemType data;
 struct Lnode *next;
};
typedef Lnode * LinkList;
void LinkListTraverse(LinkList L) //遍历链表表示的多项式
{
Lnode *p=L->next; //头结点的下一个结点是第一个元素
while(p)
{
cout<<"("<<p->data.coef<<","<<p->data.exp<<") ";
p=p->next;
}
cout<<endl;
}
//查找
Lnode *LocatePoly(Lnode * head, int e) //在多项式 head 中查找指数为 e 的项
{ //并返回该项的位置
Lnode *r=head->next;
while(r)
{
if(r->data.exp==e) return r;
r=r->next;
}
return NULL; //若没找到返回空
}
//删除某项
void DeletePoly(Lnode *head, int e) //删除多项式中指数为 e 的项
{
Lnode *r=head->next, *p=head;
while(r)
{
if(r->data.coef==e) { p->next=r->next; delete r; } //若是该项则删除
else { p=r; r=r->next; } //继续查找
}
}
//创建多项式，指数为降序排列
Lnode *poly()
{
Lnode *head, *r, *s,*p, *q, *t;
int e, n;
head=new Lnode;
head->data.exp=32768; head->data.coef=0; head->next=NULL;
r=head;
cin>>n>>e;9
while(n!=0)
{
p=LocatePoly(head,e); //查找有无该项
if(p==NULL) //若没有，则生成结点并插入
{
s=new Lnode;
s->data.coef=n;
s->data.exp=e;
q=head;
while(q && q->data.exp>e){t=q; q=q->next;} //查找插入位置
 if(q==NULL){ t->next=s; s->next=NULL;} //若在最后插入时
else{ t->next=s; s->next=q;} //在中间位置插入时
}
else //若在该多项式中已存在该指数的项
{
if((p->data.coef+n)==0) DeletePoly(head,e);
else p->data.coef+=n;
}
cin>>n>>e;
}
return head;
}
5、多项式加法
Lnode * padd(Lnode *heada, Lnode *headb) //对两个多项式求和
{
Lnode *headc, *p, *q, *s, *r;
int x;
p=heada->next; q=headb->next;
headc=new Lnode;
r=headc;
while(p!=NULL && q!=NULL) //当两个多项式都没到头时
{
if(p->data.exp==q->data.exp) //若指数项相等
{
x=p->data.coef+q->data.coef; //计算系数之和
if(x!=0) //若非零，则生成结点
{
s= new Lnode; s->data.coef=x;
s->data.exp=p->data.exp; r->next=s; r=s;
}
p=p->next; q=q->next;
}
else //若指数项不等
{
if(p->data.exp<q->data.exp) //比较指数的大小10
{ //若小于，则插入第二个
s=new Lnode; s->data.coef=q->data.coef;
s->data.exp=q->data.exp; r->next=s;
r=s; q=q->next;
}
else //比较指数的大小
{ //若大于，则插入第一个
s=new Lnode; s->data.coef=p->data.coef;
s->data.exp=p->data.exp; r->next=s;
r=s; p=p->next;
}
}
}
while(p!=NULL) //第一个多项式没到头时
{
s=new Lnode; s->data.coef=p->data.coef;
s->data.exp=p->data.exp; r->next=s;
r=s; p=p->next;
}
while(q!=NULL) //第二个多项式没到头时
{
s=new Lnode; s->data.coef=q->data.coef;
s->data.exp=q->data.exp; r->next=s;
r=s; q=q->next;
}
r->next=NULL;
return headc;
}
void main()
{
 cout<<"please input the coefficient and exponent of a polynormal:"<<endl;
LinkList L1=poly();
LinkListTraverse(L1);
LinkList L2=poly();
LinkListTraverse(L2);
 cout<<"the sum of two polynormal:"<<endl;
LinkList L3=padd(L1,L2);
LinkListTraverse(L3);
}
