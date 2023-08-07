#include <stdio.h>
#include <stdlib.h>
#define MaxVex      100          //最多顶点个数
#define INFINITY    32768        //表示极大值，即∞
#define MAX_VERtEX_NUM 20
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define VRType int                          //表示顶点之间的关系的变量类型
#define InfoType char                       //存储弧或者边额外信息的指针变量类型


typedef enum{false,true}bool;               //定义bool型常量
bool visited[MAX_VERtEX_NUM];               //设置全局数组，记录标记顶点是否被访问过
typedef char VertexType;                  //假设顶点数据类型为字符类型
typedef int  EdgeType;                     //对于无权图，用1或0表示是否相邻，对带权图，则为权值类型
typedef struct
{
    VertexType vertex[MaxVex];           //顶点数组
    EdgeType arcs[MaxVex][MaxVex];       //邻接矩阵
    int  vexnum,arcnum;                  //图中的顶点数和边数
}Graph;

typedef struct Queue{
    VertexType data;
    struct Queue * next;
}Queue;

typedef struct {
    VRType adj;                             //对于无权图，用 1 或 0 表示是否相邻；对于带权图，直接为权值。
    InfoType * info;                        //弧或边额外含有的信息指针
}ArcCell,AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];

typedef struct {
    VertexType vexs[MAX_VERtEX_NUM];        //存储图中顶点数据
    AdjMatrix arcs;                         //二维数组，记录顶点之间的关系
    int vexnum,arcnum;                      //记录图的顶点数和弧（边）数
}MGraph;

                   //访问标志数组
void init(Graph *G);                    //初始化邻接矩阵
int LocateVertex(Graph *G,VertexType v);//求顶点位置函数
int createUDG(Graph *G);                //创建一个无向图
void DepthFirstSearch(Graph G, int i);  //图的深度优先遍历
void BreadthFirstSearch(Graph G,int i); //图的广度优先遍历
void TraverseGraph(Graph G);
int FirstAdjVex(MGraph G,int v);
int NextAdjVex(MGraph G,int v,int w);
void visitVex(MGraph G, int v);
void BFSTraverse(MGraph G);

int main()
{
    Graph G;
    int choice;
    while(1)
    {
        printf("----Please enter your choice----\n\n");
        printf("    choice 1：Initialization\n");
        printf("    choice 2：Create Graph\n");
        printf("    choice 3：Depth First Search\n");
        printf("    choice 4：breadth First Search\n");
        printf("    choice 0：exit\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                init(&G);
                break;
            case 2:
                (createUDG(&G)==1)?printf("Create Graph success.\n"):printf("Create Graph ERROR\n");
                break;
            case 3:
                printf("图的深度优先遍历为: ");
                TraverseGraph(G);
                break;
            case 4:
                printf("图的广度优先遍历为：");
                TraverseGraph(G);
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("ERROR！！\n");
                exit(0);
                break;
        }
    }
    return 0;
}

void init(Graph *G)   //初始化邻接矩阵
{
    int i,j;
    printf("请输入图的顶点个数和边数：");
    scanf("%d %d",&(G->vexnum),&(G->arcnum));//输入图的顶点个数和边数
    for(i=0;i<G->vexnum;i++)              //初始化
    {
        for(j=0;j<G->vexnum;j++)
        {
            G->arcs[i][j]=INFINITY;
        }
    }
    printf("图的初始化成功\n");
}

int LocateVertex(Graph *G,VertexType v)  //查找并返回顶点的位置
{
    int j=0,k;
    for(k=0;k<G->vexnum;k++)
    {
        if(G->vertex[k]==v)
        {
            j=k;
            break;
        }
    }
    return j;
}

int createUDG(Graph *G)  //创建一个无向图
{
    int i,j,k,weight;
    VertexType v1,v2;
    for(i=0;i<G->vexnum;i++)
    {
        printf("请输入图的第 %d 顶点：",i+1);
        getchar();
        scanf("%c",&(G->vertex[i]));     //输入图的顶点集
    }
    for(k=0;k<G->arcnum;k++)
    {
        printf("请分别输入图的第 %d 条边的两个顶点和权值",k+1);
        getchar();
        scanf("%c %c %d",&v1,&v2,&weight);//输入一条边的两个顶点、权值
        i=LocateVertex(G,v1);
        j=LocateVertex(G,v2);
        G->arcs[i][j]=weight;     //建立顶点之间的关系
        G->arcs[j][i]=weight;
    }
    return OK;
}

void DepthFirstSearch(Graph G, int i)   //图的深度优先遍历
{
    int j;
    visited[i] = TRUE;
    printf("%c ",G.vertex[i]);
    for (j=0; j<G.vexnum; j++)
    {
        if (G.arcs[i][j]!=INFINITY  &&  !visited[j])
            DepthFirstSearch(G,j);
    }
}

int FirstAdjVex(MGraph G,int v)
{
    //查找与数组下标为v的顶点之间有边的顶点，返回它在数组中的下标
    for(int i = 0; i<G.vexnum; i++){
        if( G.arcs[v][i].adj ){
            return i;
        }
    }
    return -1;
}

int NextAdjVex(MGraph G,int v,int w)
{
    //从前一个访问位置w的下一个位置开始，查找之间有边的顶点
    for(int i = w+1; i<G.vexnum; i++){
        if(G.arcs[v][i].adj){
            return i;
        }
    }
    return -1;
}

//操作顶点的函数
void visitVex(MGraph G, int v)
{
    printf("%d ",G.vexs[v]);
}

//初始化队列
void InitQueue(Queue ** Q){
    (*Q)=(Queue*)malloc(sizeof(Queue));
    (*Q)->next=NULL;
}

//顶点元素v进队列
void EnQueue(Queue **Q,VertexType v){
    Queue * element=(Queue*)malloc(sizeof(Queue));
    element->data=v;
    Queue * temp=(*Q);
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=element;
}

//队头元素出队列
void DeQueue(Queue **Q,int *u){
    (*u)=(*Q)->next->data;
    (*Q)->next=(*Q)->next->next;
}

//判断队列是否为空
bool QueueEmpty(Queue *Q){
    if (Q->next==NULL) {
        return true;
    }
    return false;
}

//广度优先搜索
void BFSTraverse(MGraph G)
   {
    int v;
    //将用做标记的visit数组初始化为false
    for( v = 0; v < G.vexnum; ++v)
    {
        visited[v] = false;
    }
    //对于每个标记为false的顶点调用深度优先搜索函数
    Queue * Q;
    InitQueue(&Q);
    for( v = 0; v < G.vexnum; v++)
    {
        if(!visited[v])
        {
            visited[v]=true;
            visitVex(G, v);
            EnQueue(&Q, G.vexs[v]);
            while (!QueueEmpty(Q))
            {
                int u;
                DeQueue(&Q, &u);
                u=LocateVertex(&G, u);
                for (int w=FirstAdjVex(G, u); w>=0; w=NextAdjVex(G, u, w))
                {
                    if (!visited[w])
                    {
                        visited[w]=true;
                        visitVex(G, w);
                        EnQueue(&Q, G.vexs[w]);
                    }
                }
            }
        }
    }
}
void TraverseGraph(Graph G)
{
    int i;
    for (i=0; i<G.vexnum; i++)   //初始化访问标志数组
        visited[i] = FALSE;

    for (i=0; i<G.vexnum; i++)//循环调用深度优先遍历连通子图的操作，若图G是连通图，则此调用只执行一次
    {
        if (!visited[i])
            DepthFirstSearch(G, i);
    }
    printf("\n");
}
