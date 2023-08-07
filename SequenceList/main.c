#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

int main()
{
    SqList La;
    La=InitList(La);
    return 0;
}

//ͷ�ļ�
#include<iostream.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
//��������
const int LIST_INIT_SIZE=100; //�����ʼ����
const int LISTINCREMENT=10; //����ʱ������
const int OVERFLOW=-1;
typedef char ElemType;
struct SqList2
{
 ElemType *elem; //�洢Ԫ�صĻ���ַ
 int length; //������
 int listsize; //��������
};
//���Ա�ĳ�ʼ������
void InitList_Sq(SqList &L) //L Ϊ����ʼ��˳��������
{
 L.elem=new ElemType[LIST_INIT_SIZE]; //�������ݿռ�
 if(!L.elem) exit(OVERFLOW); //�жϷ����Ƿ�ɹ�
 L.length=0; L.listsize= LIST_INIT_SIZE; //��ʼ������������
}
//���Ա�����ٺ���
void DestroyList_Sq(SqList &L) //L Ϊ������˳��������
{
 free() [] L.elem; //�ͷ��ڴ�ռ�
 L.listsize=0; L.length=0; //�������������
}
//���Ա�Ĳ������
void ListInsert_Sq(SqList &L, int I, ElemType e) //L Ϊ���������Ա�I Ϊ����
 //λ�ã�e Ϊ������Ԫ��ֵ
{
 ElemType *newbase, *q;
if(I<1 || I>L.length+1) cout<<"error"; //�ж� I �ĺ�����
 if(L.length >= L.listsize) //�����������������Ҫ���ݣ�
 {
 newbase=(ElemType *) realloc(L.elem,
 (L.listsize+LISTINCREMENT)*sizeof(ElemType));
 if(!newbase) exit(OVERFLOW);
 L.elem=newbase; L.listsize+=LISTINCREMENT;
 }
 q=&(L.elem[I-1]); //��¼�����ַ
 for(ElemType *p=&(L.elem[L.length-1]); p>=q; --p)
 *(p+1)=*p; //��ǰ�ƶ�Ԫ��
 *q=e; ++L.length; //����Ԫ�أ������±�
}
//���Ա��ɾ������
void ListDelete_Sq(SqList &L, int I, ElemType &e) //L Ϊ��ɾ�����Ա�I Ϊɾ��
{ //λ�ã�ͨ�� e ����ɾ��Ԫ��ֵ
 if(I<1 || I>L.length) return ; //�ж� I �ĺ�����
 ElemType *p=&(L.elem[I-1]); e=*p; //��¼ɾ��Ԫ��
 ElemType *q=L.elem+L.length-1; //��¼���Ա�ı�β��ַ
 for(++p; p<=q; ++p) *(p-1)=*p; //Ԫ����ǰ�ƶ�
 -- L.length; //���±�
}
//���Ա����ղ���3
void ClearList_Sq(SqList &L){ L.length=0;} //L Ϊ��������Ա�
//���Ա���пղ���
int ListEmpty_Sq(SqList L)
{
if(L.length==0) return 1; //������Ϊ 0 �����Ա�Ϊ��
else return 0;
}
//�����
int ListLength_Sq(SqList L){ return L.length; }
//�������Ա���ֵ���Ƚ�
int compare(SqList La, SqList Lb) //La �� Lb �ֱ��ʾ�������Ƚ����Ա�
{
 int j=1; //�������Ա���Ԫ�ص�λ��
 while(j<=La.length && j<=Lb.length) //��������û����βʱ����
 {
 if(La.elem[j]<Lb.elem[j]) return -1; //�Ƚ϶�ӦԪ�أ��õ���Ӧ���
 else if(La.elem[j]>Lb.elem[j]) return 1;
 else j++;
 } //���������������Ѿ��Ƚϳ��������ֹͣ����û�У������
 if(La.length==Lb.length) return 0; //�����������˱�βʱ�����
 else if(La.length<Lb.length)return -1; //�Ƚ�������ĳ��ȣ����ȴ���Ϊ��
 else return 1;
}
void main()
{
SqList La,Lb; //�����������Ա�
char ch1[80],ch2[80]; //���մӼ���������ַ�����
 InitList_Sq(La); InitList_Sq(Lb); //��ʼ���������Ա�
cout<<"please input the first string:"<<endl;
cin.getline(ch1,80,'\n'); //�Ӽ��������ַ���� 80 �����Իس�Ϊ����
 //��ʶ�����յ��ĵ�һ���ַ����洢�ڱ� La ��
for(int i=0;i<strlen(ch1);i++) ListInsert_Sq(La, i+1, *(ch1+i));
 cout<<"please input the second string:"<<endl;
cin.getline(ch2,80,'\n'); //�Ӽ��������ַ���� 80 �����Իس�Ϊ������ʶ
 //�����յ��ĵ�һ���ַ����洢�ڱ� Lb ��
for(i=0;i<strlen(ch2);i++) ListInsert_Sq(Lb, i+1, *(ch2+i));
 cout<<"the result ot comparation:"<<endl;
cout<<compare(La,Lb)<<endl; //����ȽϽ��
}

//ͷ�ļ�
#include<iostream.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef int ElemType;
const int OVERFLOW=-1;5
struct Lnode{ //�����еĽ��
 ElemType data; //������
 struct Lnode *next; //ָ����
};
typedef Lnode * LinkList; //�������������������
//����ĳ�ʼ��
void InitList_L(LinkList &L) //L Ϊ����ʼ��������
{
 L=new Lnode[1]; //����ͷ���Ŀռ�
 if(!L) exit(OVERFLOW);
 L->next=NULL; //β��ָ�븳ֵΪ��
}
//��������
void DestroyList_L(LinkList &L)
{
 Lnode *p=L; //������ʱָ��
p=p->next; //ָ���һ��Ԫ��
 while(p) //�� p �ǿ�ʱ����
{
L->next=p->next; //��ͷָ�����
delete p; //�ͷ���ʱ�� p �Ŀռ�
p=L->next; //����ָ���һ��Ԫ��
}
}
//ȡԪ�ز���
void GetElem_L(LinkList L, int I, ElemType &e) //L Ϊ��Ӧ������I ΪȡԪ�ص�
 //λ�ã�ͨ�� e ����ȡ����Ԫ��ֵ
{
 Lnode *p=L->next; //�� p ָ���һ��Ԫ��
int j=1;
 while (p && j<I) { p=p->next; ++j; } //��λȡԪ�ص�λ��
 if(!p || j>I) return; //��û�ҵ�λ�ã������
 e=p->data; //����Ҫ�ҵ�ֵ
}
//������ĳ���
int ListLength_L(LinkList L)
{
 Lnode *p=L->next;
int k=0;
 while(p) //�ӵ�һ��Ԫ�ؿ�ʼ����
 {
 k++; p=p->next;
 }
 return k;
}
//��λԪ��6
Lnode *LocateElem_L(LinkList L, ElemType e) //e ΪҪ���ҵ�Ԫ��
{
 Lnode *p=L;
 while(p && p->data!=e)p=p->next; //���β��ҵĹ���
 return p; //���ز��ҵĽ������ձ�ʾû�ҵ�
}
//����Ԫ��
void ListInsert_L(LinkList &L, int I, ElemType e) //������ L �е� I ��λ�ò���Ԫ�� e
{
 Lnode *p=L;
int j=0;
 while(p && j<I-1){ p=p->next ;++j;} //���Ҳ���λ��
 if(!p || j>I-1) cout<<"ERROR";
 Lnode *s=new Lnode[1]; //���ɽ��
 s->data=e; s->next=p->next; p->next=s; //�������
}
//����ɾ��
void ListDelete_L(LinkList &L, int I, ElemType &e) //ɾ������ L �е� I ��Ԫ�أ�
 //������ e ���ء�
{
 Lnode *p=L;
int j=0;
 while(p && j<I-1){p=p->next; ++j;} //����Ҫɾ��Ԫ�ص�λ��
 if(!p || j>I-1) cout<<"ERROR";
 Lnode *q=p->next; p->next=q->next; e=q->data; //ǰ�����������
delete q; //�ͷſռ�
}
//��������
void LinkListTraverse(LinkList L)
{
Lnode *p=L->next;
while(p) //������������е�Ԫ��
{
cout<<p->data<<" ";
p=p->next;
}
cout<<endl;
}
//2�����򴴽�����
//������ķ�ʽ������������������������һ��Ԫ�أ��������а��� n ��Ԫ�ء�
void CreateList_L(LinkList &L, int n)
{
 for (int I=n; I>0;--I)
 {7
 Lnode *p=new Lnode; //���ɽ��ռ�
 cin>>p->data;
 p->next=L->next; L->next=p; //��������λ��
 }
}
//3����������
//��������ɾ������Ԫ�أ������򴴽��ķ������뵽��һ�������У��ﵽ���������Ŀ�ġ�
void InvertLinkedList(LinkList &L)
{
 Lnode *p=L->next, *s,*q=NULL;
 while(p)
 { //s Ϊԭ�������Ԫ�أ����ν� s ���������ף��Ӷ��ﵽ����
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
typedef struct polyitem //�����н���������
{
int coef; //ϵ��
int exp; //ָ��
}ElemType; 8
const int OVERFLOW=-1;
struct Lnode{ //�����н������
 ElemType data;
 struct Lnode *next;
};
typedef Lnode * LinkList;
void LinkListTraverse(LinkList L) //���������ʾ�Ķ���ʽ
{
Lnode *p=L->next; //ͷ������һ������ǵ�һ��Ԫ��
while(p)
{
cout<<"("<<p->data.coef<<","<<p->data.exp<<") ";
p=p->next;
}
cout<<endl;
}
//����
Lnode *LocatePoly(Lnode * head, int e) //�ڶ���ʽ head �в���ָ��Ϊ e ����
{ //�����ظ����λ��
Lnode *r=head->next;
while(r)
{
if(r->data.exp==e) return r;
r=r->next;
}
return NULL; //��û�ҵ����ؿ�
}
//ɾ��ĳ��
void DeletePoly(Lnode *head, int e) //ɾ������ʽ��ָ��Ϊ e ����
{
Lnode *r=head->next, *p=head;
while(r)
{
if(r->data.coef==e) { p->next=r->next; delete r; } //���Ǹ�����ɾ��
else { p=r; r=r->next; } //��������
}
}
//��������ʽ��ָ��Ϊ��������
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
p=LocatePoly(head,e); //�������޸���
if(p==NULL) //��û�У������ɽ�㲢����
{
s=new Lnode;
s->data.coef=n;
s->data.exp=e;
q=head;
while(q && q->data.exp>e){t=q; q=q->next;} //���Ҳ���λ��
 if(q==NULL){ t->next=s; s->next=NULL;} //����������ʱ
else{ t->next=s; s->next=q;} //���м�λ�ò���ʱ
}
else //���ڸö���ʽ���Ѵ��ڸ�ָ������
{
if((p->data.coef+n)==0) DeletePoly(head,e);
else p->data.coef+=n;
}
cin>>n>>e;
}
return head;
}
5������ʽ�ӷ�
Lnode * padd(Lnode *heada, Lnode *headb) //����������ʽ���
{
Lnode *headc, *p, *q, *s, *r;
int x;
p=heada->next; q=headb->next;
headc=new Lnode;
r=headc;
while(p!=NULL && q!=NULL) //����������ʽ��û��ͷʱ
{
if(p->data.exp==q->data.exp) //��ָ�������
{
x=p->data.coef+q->data.coef; //����ϵ��֮��
if(x!=0) //�����㣬�����ɽ��
{
s= new Lnode; s->data.coef=x;
s->data.exp=p->data.exp; r->next=s; r=s;
}
p=p->next; q=q->next;
}
else //��ָ�����
{
if(p->data.exp<q->data.exp) //�Ƚ�ָ���Ĵ�С10
{ //��С�ڣ������ڶ���
s=new Lnode; s->data.coef=q->data.coef;
s->data.exp=q->data.exp; r->next=s;
r=s; q=q->next;
}
else //�Ƚ�ָ���Ĵ�С
{ //�����ڣ�������һ��
s=new Lnode; s->data.coef=p->data.coef;
s->data.exp=p->data.exp; r->next=s;
r=s; p=p->next;
}
}
}
while(p!=NULL) //��һ������ʽû��ͷʱ
{
s=new Lnode; s->data.coef=p->data.coef;
s->data.exp=p->data.exp; r->next=s;
r=s; p=p->next;
}
while(q!=NULL) //�ڶ�������ʽû��ͷʱ
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
