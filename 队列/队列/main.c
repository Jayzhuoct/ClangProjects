#include<stdio.h>
#define maxsize 50
typedef struct{
 int a[maxsize];
 int front;
 int rear;
 //int tag=0;
}seqqueue;
void initqueue(seqqueue *p){
 p->front=p->rear=0;
}
int enterqueue(seqqueue *p,int x){
 if((p->rear+1%maxsize==p->front))
 return 0;
 p->a[p->rear]=x;
 p->rear=(p->rear+1)%maxsize;
 return 1;
}
int deletequeue(seqqueue *q,int *x){
 if(q->front==q->rear)
 return 0;
 *x=q->a[q->front];
 q->front=(q->front+1)%maxsize;
 return 1;
}
void getheard(seqqueue *p,int *x){
 *x=p->a[p->front];
}
int isEmpty(seqqueue *p){
 if(p->front==p->rear)
 return 1;
 else return 0;
}
void YangHuiTriangle()
{
 printf("请输入你要打印的杨辉三角的层数：");
 int y;
 scanf("%d",&y);
 int temp,x;
 int a,b;
 seqqueue Q;
 initqueue(&Q);
 enterqueue(&Q,1);
 for(int n=2;n<=y;n++){
  enterqueue(&Q,1);
  for(int i=1;i<=n-2;i++){
   deletequeue(&Q,&temp);
   printf("%d ",temp);
   getheard(&Q,&x);
   temp=temp+x;
   enterqueue(&Q,temp);
  }

  deletequeue(&Q,&x);
  printf("%d ",x);
  enterqueue(&Q,1);
  printf("\n");
 }

 while(!isEmpty(&Q)){
 deletequeue(&Q,&x);
    printf("%d ",x);
 }
}
int main(){
 YangHuiTriangle();
}
