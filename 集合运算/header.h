#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define ERROR  -1
//创建结构体
typedef struct Node{
 int data;
 struct Node *next;
}Node,*Link;

void clear(Link l);
Link list(Link l);
Link input(Link l,int n);
Link output(Link l);
Link binji(Link La,Link Lb,Link Lc);
Link jiaoji(Link La,Link Lb,Link Ld);
Link caji(Link La,Link Lb,Link Le);
void show ();

#endif // HEADER_H_INCLUDED
