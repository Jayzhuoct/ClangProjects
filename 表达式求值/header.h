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
}ST;//ջ��������׺ת��׺

int isempty(ST *T); //�ж�ջ�Ƿ�Ϊ��
int isfull(ST *T);  //�ж�ջ�Ƿ�Ϊ��
int gettop(ST *T);  //�õ�ջ��Ԫ��
int pop(ST *T);  //��ջ
void push(ST *T,int s);  //��ջ
void transfer(char *in,char *post);   //��׺ת��׺
float Calculate_zhong(char *post);    //�����ֵ���ú�׺�����㣩

#endif // HEADER_H_INCLUDED
