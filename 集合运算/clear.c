#include <stdio.h>
#include <stdlib.h>
#define ERROR  -1
#include"header.h"
//清空链表
void clear(Link l){
 Link p,q;
 p=l->next;
 if(!p){
  return;
 }
 while(p!=NULL){
  q=p;
  p=p->next;
  free(q);     //释放节点空间
 }
 l->next=NULL;       //将l链表的next指针域置空
 printf("This part is over\n");
}
