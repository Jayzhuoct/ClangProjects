#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
//常量定义
const int LIST_INIT_SIZE=100;	//链表初始容量
const int LISTINCREMENT=10;	//扩容时的增量const int OVERFLOW=-1;
typedef char ElemType;

struct SqList
{
ElemType *elem;//存储元素的基地址
int	length;	//链表长度
int	listsize;//链表容量
};//线性表的初始化函数
void InitList_Sq(SqList) &L)	//L 为待初始化顺序表的引用
{
L.elem=new ElemType[LIST_INIT_SIZE];	//分配内容空间
if(!L.elem) exit(OVERFLOW);	//判断分配是否成功
L.length=0;	L.listsize= LIST_INIT_SIZE;	//初始化长度与容量
};
//线性表的销毁函数
void DestroyList_Sq(SqList	&L)	//L为待销毁顺序表的引用
{
delete [] L.elem;	//释放内存空间
L.listsize=0;	L.length=0;	//长度与容量清空
}
//线性表的插入操作
void	ListInsert_Sq(SqList &L, int I, ElemType e)	//L 为待插入线性表，I 为插入
//位置，e 为待插入元素值
{
  ElemType *newbase, *q;
  if(I<1 || I>L.length+1) cout<<"error";	//判断 I 的合理性
  if(L.length >= L.listsize)	//如果条件成立，则需要扩容，
{
  newbase=(ElemType *) realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
  if(!newbase)
  exit(OVERFLOW);
  L.elem=newbase;
  L.listsize+=LISTINCREMENT;
}
  q=&(L.elem[I-1]);	//记录插入地址
  for(ElemType *p=&(L.elem[L.length-1]); p>=q; --p)
  *(p+1)=*p;	//向前移动元素
  *q=e;
  ++L.length;	//插入元素，并更新表长
}
//线性表的删除操作
void	ListDelete_Sq(SqList &L, int I, ElemType &e)	//L为待删除线性表，I为删除
{	//位置，通过e带回删除元素值
  if(I<1 || I>L.length)
  return ;//判断I的合理性
  ElemType *p=&(L.elem[I-1]);	e=*p;// 记录删除元素
  ElemType *q=L.elem+L.length-1;//记录线性表的表尾地址
  for(++p; p<=q; ++p)
  *(p-1)=*p;//元素向前移动
  --L.length;	//更新表长
}
//线性表的清空操作

void ClearList_Sq(SqList &L){ L.length=0;}	//L为待清空线性表
//线性表的判空操作
int ListEmpty_Sq(SqList L)
{
  if(L.length==0)
  return 1;	//若长度为0则线性表为空
  else return 0;
}
//求表长度
int ListLength_Sq(SqList L){return L.length; }
//两个线性表的字典序比较
int compare(SqList La, SqList Lb)	//La和Lb分别表示两个待比较线性表
{
int j=1;			//控制线性表中元素的位置
while(j<=La.length	&&	j<=Lb.length)	//当两个表都没到表尾时继续
{
if(La.elem[j]<Lb.elem[j])
    return -1;	//比较对应元素，得到相应结果
    else if(La.elem[j]>Lb.elem[j])
    return 1;
else j++;
} //结束条件可能是已经比较出结果，则停止，若没有，则继续
  if(La.length==Lb.length)
  return 0;		//当两个表都到了表尾时，相等
  else if(La.length<Lb.length)return -1;	//比较两个表的长度，长度大者为大
  else return 1;
}
void main()
{
  SqList La,Lb;	//声明两个线性表
  char ch1[80],ch2[80];		//接收从键盘输入的字符数组
  InitList_Sq(La);
  InitList_Sq(Lb);	//初始化两个线性表
  printf("please input the first string:");
  scanf(ch1,80,'\n');	//从键盘输入字符，最长 80 个，以回车为结束
//标识将接收到的第一个字符串存储在表La中
for(int i=0;i<strlen(ch1);i++)
    ListInsert_Sq(La, i+1, *(ch1+i));
  printf("please input the second string:");
  scanf(ch2,80,'\n');	//从键盘输入字符，最长 80 个，以回车为结束标识
//将接收到的第一个字符串存储在表 Lb 中
for(i=0;i<strlen(ch2);i++)
  ListInsert_Sq(Lb, i+1, *(ch2+i));
  printf("the result ot comparation:");
  printf(compare(La,Lb));	//输出比较结果
}
