#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 3
#define MAX_VERTEX_NUM 20
typedef int InfoType;					//存放网的权值
typedef char VertexType[MAX_NAME];		//字符串类型
typedef enum{DG, DN, AG, AN}GraphKind;	//{有向图，有向网，无向图，无向网}
//图的邻接表存储
typedef struct ArcNode
{
	int adjvex;							//该弧所指向的顶点的位置
	struct ArcNode *nextarc;			//指向吓一条的指针
	InfoType *info;						//网的权值指针
}ArcNode;

typedef struct VNode
{
	VertexType data;					//顶点信息
	ArcNode *firstarc;					//第一个表结点的地址，指向第一条依附该顶点的弧的指针
}VNode, AdjList[MAX_VERTEX_NUM];		//头结点

typedef struct
{
		AdjList vertices;
		int vexnum, arcnum;				//图的当前顶点数和弧数
		int kind;						//图的种类标志
}ALGraph;

//若G中存在顶点u，则返回该顶点在图中的位置。都则返回-1
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

//採用邻接表存储结构，构造没有相关信息的图G(用一个函数构造4种图)
int CreateGraph(ALGraph *G)
{
	int i, j, k;
	int w;							//权值
	VertexType va, vb;
	ArcNode *p;
	printf("请输入图的类型（有向图：0，有向网：1。无向图：2，无向网：3）:");
	scanf("%d", &(*G).kind);
	printf("请输入图的顶点数和边数:(以空格间隔)： \n");
	scanf("%d%d", &(*G).vexnum, &(*G).arcnum);
	printf("请输入%d个顶点的值(小于%d个字符):\n", (*G).vexnum, MAX_NAME);
	for(i = 0; i < (*G).vexnum; ++i)                //构造顶点向量
	{
		scanf("%s", (*G).vertices[i].data);
		(*G).vertices[i].firstarc = NULL;
	}
	if((*G).kind == 1 || (*G).kind == 3)		//网
	{
		printf("请顺序输入每条弧（边）的权值,弧尾和弧头（以空格作为间隔）:\n");
	}
	else											//图
	{
		printf("请顺序输入每条弧（边）的弧尾和弧头（以空格作为间隔）:\n");
	}
	for(k = 0; k < (*G).arcnum; ++k)
	{
		if((*G).kind == 1 || (*G).kind == 3)
				scanf("%d%s%s", &w, va, vb);
		else
				scanf("%s%s", va, vb);
		i = LocateVex(*G, va);					//弧尾
		j = LocateVex(*G, vb);					//弧头
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
		p->nextarc = (*G).vertices[i].firstarc;                 //插在表头
		(*G).vertices[i].firstarc = p;
		if((*G).kind >= 2)										//无向图或网。产生第二个表结点
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
			p->nextarc = (*G).vertices[j].firstarc;               //插在表头
			(*G).vertices[j].firstarc = p;
		}
	}
	return 1;
}

//输出图的邻接表G
void Display(ALGraph G)
{
	int i;
	ArcNode *p;
	switch(G.kind)
	{
		case DG:
				printf("有向图\n");
				break;
		case DN:
				printf("有向网\n");
				break;
		case AG:
				printf("无向图\n");
				break;
		case AN:
				printf("无向网\n");
	}
	printf("%d 个顶点: \n", G.vexnum);
	for(i = 0; i < G.vexnum; ++i)
	{
		printf("%s ", G.vertices[i].data);
	}
	printf("\n%d条弧（边）:\n", G.arcnum);
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


//求顶点的入度
void FindInDegree(ALGraph G, int indegree[])
{
	int i;
	ArcNode *p;
	//赋初值
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

//栈类型
typedef int SElemType;
#define STACK_INIT_SIZE 10										//存储空间初始分配量
#define STACKINCREMENT 2										//存储空间分配增量

//栈的顺序存储结构表示
typedef struct SqStack
{
	SElemType *base;						//基地址
	SElemType *top;							//栈顶指针
	int stacksize;							//当前已经分配的存储空间
}SqStack;

//构造一个空栈
int InitStack(SqStack *S)
{
	//为栈底分分配一个指定大小的存储空间
	(*S).base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!(*S).base)
			exit(0);
	(*S).top = (*S).base;					//栈底与栈顶指针同样
	(*S).stacksize = STACK_INIT_SIZE;
	return 1;
}



//若栈S为空栈（栈底指针和栈顶指针同样）, 则返回1。否则返回0
int StackEmpty(SqStack S)
{
	if(S.top == S.base)
			return 1;
	else
			return 0;
}


//插入元素e为新的栈顶元素
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




//若栈不为空，则删除S栈顶元素用e返回其值。并返回1。否则返回0
int Pop(SqStack *S, SElemType *e)
{
	if((*S).top == (*S).base)
	{
		return 0;
	}
	*e = *--(*S).top;
	return 1;
}


//有向图的G採用邻接表存储结构。若G无回路，则输出G的顶点的一个拓扑结构
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
		//栈不空
		while(!StackEmpty(S))
		{
			Pop(&S, &i);
			printf("%s", G.vertices[i].data);			//输出i号顶点并计数
			++count;
			//对i号顶点的每一个邻接点的入度减1
			for(p == G.vertices[i].firstarc; p; p = p->nextarc)
			{
				k = p->adjvex;
				if(!(--indegree[k]))			//若入度减为0，则入栈
						Push(&S, k);
			}
		}
		if(count < G.vexnum)
		{
				printf("此有向图有回路\n");
				return 0;
		}
		else
		{
			printf("为一个拓扑序列!!\n");
		}
	}
}

int main()
{
	ALGraph f;
	printf("请选择有向图\n");
	CreateGraph(&f);
	Display(f);
	TopologicalSort(f);
	return 0;
}
