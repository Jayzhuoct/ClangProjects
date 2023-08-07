#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 3
#define MAX_VERTEX_NUM 20
typedef int InfoType;					//�������Ȩֵ
typedef char VertexType[MAX_NAME];		//�ַ�������
typedef enum{DG, DN, AG, AN}GraphKind;	//{����ͼ��������������ͼ��������}
//ͼ���ڽӱ�洢
typedef struct ArcNode
{
	int adjvex;							//�û���ָ��Ķ����λ��
	struct ArcNode *nextarc;			//ָ����һ����ָ��
	InfoType *info;						//����Ȩֵָ��
}ArcNode;

typedef struct VNode
{
	VertexType data;					//������Ϣ
	ArcNode *firstarc;					//��һ������ĵ�ַ��ָ���һ�������ö���Ļ���ָ��
}VNode, AdjList[MAX_VERTEX_NUM];		//ͷ���

typedef struct
{
		AdjList vertices;
		int vexnum, arcnum;				//ͼ�ĵ�ǰ�������ͻ���
		int kind;						//ͼ�������־
}ALGraph;

//��G�д��ڶ���u���򷵻ظö�����ͼ�е�λ�á����򷵻�-1
int LocateVex(ALGraph G, VertexType u)
{
	int i;
	for(i = 0; i < G.vexnum; ++i)
	{
		if(strcmp(u, G.vertices[i].data) == 0)
				return i;
		return -1;
	}
}

//�����ڽӱ�洢�ṹ������û�������Ϣ��ͼG(��һ����������4��ͼ)
int CreateGraph(ALGraph *G)
{
	int i, j, k;
	int w;							//Ȩֵ
	VertexType va, vb;
	ArcNode *p;
	printf("������ͼ�����ͣ�����ͼ��0����������1������ͼ��2����������3��:");
	scanf("%d", &(*G).kind);
	printf("������ͼ�Ķ������ͱ���:(�Կո���)�� \n");
	scanf("%d%d", &(*G).vexnum, &(*G).arcnum);
	printf("������%d�������ֵ(С��%d���ַ�):\n", (*G).vexnum, MAX_NAME);
	for(i = 0; i < (*G).vexnum; ++i)                //���춥������
	{
		scanf("%s", (*G).vertices[i].data);
		(*G).vertices[i].firstarc = NULL;
	}
	if((*G).kind == 1 || (*G).kind == 3)		//��
	{
		printf("��˳������ÿ�������ߣ���Ȩֵ,��β�ͻ�ͷ���Կո���Ϊ�����:\n");
	}
	else											//ͼ
	{
		printf("��˳������ÿ�������ߣ��Ļ�β�ͻ�ͷ���Կո���Ϊ�����:\n");
	}
	for(k = 0; k < (*G).arcnum; ++k)
	{
		if((*G).kind == 1 || (*G).kind == 3)
				scanf("%d%s%s", &w, va, vb);
		else
				scanf("%s%s", va, vb);
		i = LocateVex(*G, va);					//��β
		j = LocateVex(*G, vb);					//��ͷ
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		if((*G).kind == 1 || (*G).kind == 3)
		{
			p->info = (int *)malloc(sizeof(int));
			*(p->info) = w;
		}
		else
		{
			p->info = NULL;
		}
		p->nextarc = (*G).vertices[i].firstarc;                 //���ڱ�ͷ
		(*G).vertices[i].firstarc = p;
		if((*G).kind >= 2)										//����ͼ�����������ڶ�������
		{
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = i;
			if((*G).kind == 3)
			{
				p->info = (int*)malloc(sizeof(int));
				*(p->info) = w;
			}
			else
			{
				p->info = NULL;
			}
			p->nextarc = (*G).vertices[j].firstarc;               //���ڱ�ͷ
			(*G).vertices[j].firstarc = p;
		}
	}
	return 1;
}

//���ͼ���ڽӱ�G
void Display(ALGraph G)
{
	int i;
	ArcNode *p;
	switch(G.kind)
	{
		case DG:
				printf("����ͼ\n");
				break;
		case DN:
				printf("������\n");
				break;
		case AG:
				printf("����ͼ\n");
				break;
		case AN:
				printf("������\n");
	}
	printf("%d ������: \n", G.vexnum);
	for(i = 0; i < G.vexnum; ++i)
	{
		printf("%s ", G.vertices[i].data);
	}
	printf("\n%d�������ߣ�:\n", G.arcnum);
	for(i = 0; i < G.vexnum; i++)
	{
		p = G.vertices[i].firstarc;
		while(p)
		{
			if(G.kind <= 1)
			{
				printf("%s->%s", G.vertices[i].data, G.vertices[p->adjvex].data);
				if(G.kind == DN)
						printf(":%d ", *(p->info));
			}
			else
			{
				if(i < p->adjvex)
				{
					printf("%s--%s", G.vertices[i].data, G.vertices[p->adjvex].data);
					if(G.kind == AN)
						printf(":%d ", *(p->info));
				}
			}
			p = p->nextarc;

		}
		printf("\n");
	}
}


//�󶥵�����
void FindInDegree(ALGraph G, int indegree[])
{
	int i;
	ArcNode *p;
	//����ֵ
	for(i = 0; i < G.vexnum; i++)
	{
		indegree[i] = 0;
	}
	for(i = 0; i < G.vexnum; i++)
	{
		p = G.vertices[i].firstarc;
		while(p)
		{
			indegree[p->adjvex]++;
			p = p->nextarc;
		}

	}

}

//ջ����
typedef int SElemType;
#define STACK_INIT_SIZE 10										//�洢�ռ��ʼ������
#define STACKINCREMENT 2										//�洢�ռ��������

//ջ��˳��洢�ṹ��ʾ
typedef struct SqStack
{
	SElemType *base;						//����ַ
	SElemType *top;							//ջ��ָ��
	int stacksize;							//��ǰ�Ѿ�����Ĵ洢�ռ�
}SqStack;

//����һ����ջ
int InitStack(SqStack *S)
{
	//Ϊջ�׷ַ���һ��ָ����С�Ĵ洢�ռ�
	(*S).base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!(*S).base)
			exit(0);
	(*S).top = (*S).base;					//ջ����ջ��ָ��ͬ��
	(*S).stacksize = STACK_INIT_SIZE;
	return 1;
}



//��ջSΪ��ջ��ջ��ָ���ջ��ָ��ͬ����, �򷵻�1�����򷵻�0
int StackEmpty(SqStack S)
{
	if(S.top == S.base)
			return 1;
	else
			return 0;
}


//����Ԫ��eΪ�µ�ջ��Ԫ��
int Push(SqStack *S, SElemType e)
{
	if((*S).top - (*S).base >= (*S).stacksize)
	{
		(*S).base = (SElemType *)realloc((*S).base,((*S).stacksize + STACKINCREMENT)*sizeof(SElemType));
		if(!(*S).base)
				exit(0);
		(*S).top = (*S).base + (*S).stacksize;
	   	(*S).stacksize += STACKINCREMENT;
	}
	*((*S).top)++= e;
	return 1;
}




//��ջ��Ϊ�գ���ɾ��Sջ��Ԫ����e������ֵ��������1�����򷵻�0
int Pop(SqStack *S, SElemType *e)
{
	if((*S).top == (*S).base)
	{
		return 0;
	}
	*e = *--(*S).top;
	return 1;
}


//����ͼ��G�����ڽӱ�洢�ṹ����G�޻�·�������G�Ķ����һ�����˽ṹ
int TopologicalSort(ALGraph G)
{
	int i, k, count, indegree[MAX_VERTEX_NUM];
	SqStack S;
	ArcNode *p;
	FindInDegree(G, indegree);
	InitStack(&S);
	for(i = 0; i < G.vexnum; ++i)
	{
		if(!indegree[i])
				Push(&S, i);
		count = 0;
		//ջ����
		while(!StackEmpty(S))
		{
			Pop(&S, &i);
			printf("%s", G.vertices[i].data);			//���i�Ŷ��㲢����
			++count;
			//��i�Ŷ����ÿһ���ڽӵ����ȼ�1
			for(p == G.vertices[i].firstarc; p; p = p->nextarc)
			{
				k = p->adjvex;
				if(!(--indegree[k]))			//����ȼ�Ϊ0������ջ
						Push(&S, k);
			}
		}
		if(count < G.vexnum)
		{
				printf("������ͼ�л�·\n");
				return 0;
		}
		else
		{
			printf("Ϊһ����������!!\n");
		}
	}
}

int main()
{
	ALGraph f;
	printf("��ѡ������ͼ\n");
	CreateGraph(&f);
	Display(f);
	TopologicalSort(f);
	return 0;
}
