#include <stdio.h>
#include <stdlib.h>
#define ERROR  -1
#include"header.h"
//�������
void clear(Link l){
 Link p,q;
 p=l->next;
 if(!p){
  return;
 }
 while(p!=NULL){
  q=p;
  p=p->next;
  free(q);     //�ͷŽڵ�ռ�
 }
 l->next=NULL;       //��l�����nextָ�����ÿ�
 printf("This part is over\n");
}
