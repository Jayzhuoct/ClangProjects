#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 30

typedef struct my_stack
{
	int a[N];
	int top;
}ST;//栈，用来中缀转后缀

int isempty(ST *T); //判断栈是否为空
int isfull(ST *T);  //判断栈是否为满
int gettop(ST *T);  //得到栈顶元素
int pop(ST *T);  //弹栈
void push(ST *T,int s);  //入栈
void transfer(char *in,char *post);   //中缀转后缀
float Calculate_zhong(char *post);    //计算的值（用后缀来计算）

#endif // HEADER_H_INCLUDED
