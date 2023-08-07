#include <stdio.h>
#include <stdlib.h>
#define ERROR  -1
#include"header.h"
//创建空链表
Link list(Link l)
{
 Link head=(Link)malloc(sizeof(Node));         //创建头节点
 if(head==NULL){          //如果头节点未空
  return 0;
 }
 l=head;
 l->next =NULL;         //把头节点指针置空
 return l;
}

//录入数据，头插法，新的数据指针指向头节点的指针
Link input(Link l,int n)
{
 Link p;
 int i;
 printf("请输入元素\n");
 for(i=1;i<=n;i++){
  p=(Link)malloc(sizeof(Node));       //开辟新节点，及分配空间
  if(p!=NULL){              //节点开辟成功
   scanf("%d",&p->data);
   p->next=l->next;     //头插
   l->next=p;
  }else{
   return 0;
  }
 }
 printf("集合输入完成\n");
 return l;
}

//输出,遍历
Link output(Link l)
{
 Link p;
 if(l->next==NULL)
 {
  printf("该链表是空链表\n");
 }else
 {
  for(p=l->next;p!=NULL;p=p->next)
    {
   printf("%d\t",p->data);
    }
  printf("\n");
 }
}

//并集 先清空c，再用a与c比较，b与c比较，将没有的数据全插入
Link binji(Link La,Link Lb,Link Lc)
{
 Link r,s,p,q;
 p=La->next;
 while (p)
{
  q=(Link)malloc(sizeof(Node));       //生成新的节点
  q->data=p->data;
  q->next=Lc->next;             //1.将c的指针赋给q
  Lc->next=q;                   //2.再使c的指针指向q（ 头插法 ）
  p=p->next;                    //用p遍历a链表
 }
 p=Lb->next;
 while(p)
  {
  q=La->next;
  while(q&&(q->data!=p->data))
  {    //查重
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
