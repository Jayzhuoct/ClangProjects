#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
//��������
const int LIST_INIT_SIZE=100;	//�����ʼ����
const int LISTINCREMENT=10;	//����ʱ������const int OVERFLOW=-1;
typedef char ElemType;

struct SqList
{
ElemType *elem;//�洢Ԫ�صĻ���ַ
int	length;	//������
int	listsize;//��������
};//���Ա�ĳ�ʼ������
void InitList_Sq(SqList) &L)	//L Ϊ����ʼ��˳��������
{
L.elem=new ElemType[LIST_INIT_SIZE];	//�������ݿռ�
if(!L.elem) exit(OVERFLOW);	//�жϷ����Ƿ�ɹ�
L.length=0;	L.listsize= LIST_INIT_SIZE;	//��ʼ������������
};
//���Ա�����ٺ���
void DestroyList_Sq(SqList	&L)	//LΪ������˳��������
{
delete [] L.elem;	//�ͷ��ڴ�ռ�
L.listsize=0;	L.length=0;	//�������������
}
//���Ա�Ĳ������
void	ListInsert_Sq(SqList &L, int I, ElemType e)	//L Ϊ���������Ա�I Ϊ����
//λ�ã�e Ϊ������Ԫ��ֵ
{
  ElemType *newbase, *q;
  if(I<1 || I>L.length+1) cout<<"error";	//�ж� I �ĺ�����
  if(L.length >= L.listsize)	//�����������������Ҫ���ݣ�
{
  newbase=(ElemType *) realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
  if(!newbase)
  exit(OVERFLOW);
  L.elem=newbase;
  L.listsize+=LISTINCREMENT;
}
  q=&(L.elem[I-1]);	//��¼�����ַ
  for(ElemType *p=&(L.elem[L.length-1]); p>=q; --p)
  *(p+1)=*p;	//��ǰ�ƶ�Ԫ��
  *q=e;
  ++L.length;	//����Ԫ�أ������±�
}
//���Ա��ɾ������
void	ListDelete_Sq(SqList &L, int I, ElemType &e)	//LΪ��ɾ�����Ա�IΪɾ��
{	//λ�ã�ͨ��e����ɾ��Ԫ��ֵ
  if(I<1 || I>L.length)
  return ;//�ж�I�ĺ�����
  ElemType *p=&(L.elem[I-1]);	e=*p;// ��¼ɾ��Ԫ��
  ElemType *q=L.elem+L.length-1;//��¼���Ա�ı�β��ַ
  for(++p; p<=q; ++p)
  *(p-1)=*p;//Ԫ����ǰ�ƶ�
  --L.length;	//���±�
}
//���Ա����ղ���

void ClearList_Sq(SqList &L){ L.length=0;}	//LΪ��������Ա�
//���Ա���пղ���
int ListEmpty_Sq(SqList L)
{
  if(L.length==0)
  return 1;	//������Ϊ0�����Ա�Ϊ��
  else return 0;
}
//�����
int ListLength_Sq(SqList L){return L.length; }
//�������Ա���ֵ���Ƚ�
int compare(SqList La, SqList Lb)	//La��Lb�ֱ��ʾ�������Ƚ����Ա�
{
int j=1;			//�������Ա���Ԫ�ص�λ��
while(j<=La.length	&&	j<=Lb.length)	//��������û����βʱ����
{
if(La.elem[j]<Lb.elem[j])
    return -1;	//�Ƚ϶�ӦԪ�أ��õ���Ӧ���
    else if(La.elem[j]>Lb.elem[j])
    return 1;
else j++;
} //���������������Ѿ��Ƚϳ��������ֹͣ����û�У������
  if(La.length==Lb.length)
  return 0;		//�����������˱�βʱ�����
  else if(La.length<Lb.length)return -1;	//�Ƚ�������ĳ��ȣ����ȴ���Ϊ��
  else return 1;
}
void main()
{
  SqList La,Lb;	//�����������Ա�
  char ch1[80],ch2[80];		//���մӼ���������ַ�����
  InitList_Sq(La);
  InitList_Sq(Lb);	//��ʼ���������Ա�
  printf("please input the first string:");
  scanf(ch1,80,'\n');	//�Ӽ��������ַ���� 80 �����Իس�Ϊ����
//��ʶ�����յ��ĵ�һ���ַ����洢�ڱ�La��
for(int i=0;i<strlen(ch1);i++)
    ListInsert_Sq(La, i+1, *(ch1+i));
  printf("please input the second string:");
  scanf(ch2,80,'\n');	//�Ӽ��������ַ���� 80 �����Իس�Ϊ������ʶ
//�����յ��ĵ�һ���ַ����洢�ڱ� Lb ��
for(i=0;i<strlen(ch2);i++)
  ListInsert_Sq(Lb, i+1, *(ch2+i));
  printf("the result ot comparation:");
  printf(compare(La,Lb));	//����ȽϽ��
}
