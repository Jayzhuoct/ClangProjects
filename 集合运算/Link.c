#include <stdio.h>
#include <stdlib.h>
#define ERROR  -1
#include"header.h"
//����������
Link list(Link l)
{
 Link head=(Link)malloc(sizeof(Node));         //����ͷ�ڵ�
 if(head==NULL){          //���ͷ�ڵ�δ��
  return 0;
 }
 l=head;
 l->next =NULL;         //��ͷ�ڵ�ָ���ÿ�
 return l;
}

//¼�����ݣ�ͷ�巨���µ�����ָ��ָ��ͷ�ڵ��ָ��
Link input(Link l,int n)
{
 Link p;
 int i;
 printf("������Ԫ��\n");
 for(i=1;i<=n;i++){
  p=(Link)malloc(sizeof(Node));       //�����½ڵ㣬������ռ�
  if(p!=NULL){              //�ڵ㿪�ٳɹ�
   scanf("%d",&p->data);
   p->next=l->next;     //ͷ��
   l->next=p;
  }else{
   return 0;
  }
 }
 printf("�����������\n");
 return l;
}

//���,����
Link output(Link l)
{
 Link p;
 if(l->next==NULL)
 {
  printf("�������ǿ�����\n");
 }else
 {
  for(p=l->next;p!=NULL;p=p->next)
    {
   printf("%d\t",p->data);
    }
  printf("\n");
 }
}

//���� �����c������a��c�Ƚϣ�b��c�Ƚϣ���û�е�����ȫ����
Link binji(Link La,Link Lb,Link Lc)
{
 Link r,s,p,q;
 p=La->next;
 while (p)
{
  q=(Link)malloc(sizeof(Node));       //�����µĽڵ�
  q->data=p->data;
  q->next=Lc->next;             //1.��c��ָ�븳��q
  Lc->next=q;                   //2.��ʹc��ָ��ָ��q�� ͷ�巨 ��
  p=p->next;                    //��p����a����
 }
 p=Lb->next;
 while(p)
  {
  q=La->next;
  while(q&&(q->data!=p->data))
  {    //����
   q=q->next;
  }
  if(!q)
  {
   r=(Link)malloc(sizeof(Node));
   r->data=p->data;
   r->next=Lc->next;
   Lc->next=r;
  }
  p=p->next;
 }
}

Link jiaoji(Link La,Link Lb,Link Ld)
{
	Link p,q,s,k;
	p=La->next;
	while(p)
	{
		q=Lb->next;
		while(q)
		{
			if(p->data==q->data)
				break;
			else
				q=q->next;
		}
		if(q)
		{
			s=Ld->next;
			while(s)
			{
				if(s->data==p->data)
					break;
				else
					s=s->next;
			}
			if(s==NULL)
			{
				k=(Link)malloc(sizeof(Node));
				k->data=p->data;
				k->next=Ld->next;
				Ld->next=k;
			}
		}
		p=p->next;
	}
}

Link caji(Link La,Link Lb,Link Le)
{
 Link p,q,r;
 p=La->next;
 while(p)
{
  q=Lb->next;
  while(q&&(q->data!=p->data))
  {
   q=q->next;
  }
  if (!q)
  {
   r=(Link)malloc(sizeof(Node));
   r->data=p->data;
   r->next=Le->next;
   Le->next=r;
  }
  p=p->next;
 }
}
