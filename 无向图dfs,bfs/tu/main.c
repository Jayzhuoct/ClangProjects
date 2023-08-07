#include <stdio.h>
#include <stdlib.h>
#define MaxVex      100          //��ඥ�����
#define INFINITY    32768        //��ʾ����ֵ������
#define MAX_VERtEX_NUM 20
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define VRType int                          //��ʾ����֮��Ĺ�ϵ�ı�������
#define InfoType char                       //�洢�����߱߶�����Ϣ��ָ���������


typedef enum{false,true}bool;               //����bool�ͳ���
bool visited[MAX_VERtEX_NUM];               //����ȫ�����飬��¼��Ƕ����Ƿ񱻷��ʹ�
typedef char VertexType;                  //���趥����������Ϊ�ַ�����
typedef int  EdgeType;                     //������Ȩͼ����1��0��ʾ�Ƿ����ڣ��Դ�Ȩͼ����ΪȨֵ����
typedef struct
{
    VertexType vertex[MaxVex];           //��������
    EdgeType arcs[MaxVex][MaxVex];       //�ڽӾ���
    int  vexnum,arcnum;                  //ͼ�еĶ������ͱ���
}Graph;

typedef struct Queue{
    VertexType data;
    struct Queue * next;
}Queue;

typedef struct {
    VRType adj;                             //������Ȩͼ���� 1 �� 0 ��ʾ�Ƿ����ڣ����ڴ�Ȩͼ��ֱ��ΪȨֵ��
    InfoType * info;                        //����߶��⺬�е���Ϣָ��
}ArcCell,AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];

typedef struct {
    VertexType vexs[MAX_VERtEX_NUM];        //�洢ͼ�ж�������
    AdjMatrix arcs;                         //��ά���飬��¼����֮��Ĺ�ϵ
    int vexnum,arcnum;                      //��¼ͼ�Ķ������ͻ����ߣ���
}MGraph;

                   //���ʱ�־����
void init(Graph *G);                    //��ʼ���ڽӾ���
int LocateVertex(Graph *G,VertexType v);//�󶥵�λ�ú���
int createUDG(Graph *G);                //����һ������ͼ
void DepthFirstSearch(Graph G, int i);  //ͼ��������ȱ���
void BreadthFirstSearch(Graph G,int i); //ͼ�Ĺ�����ȱ���
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
        printf("    choice 1��Initialization\n");
        printf("    choice 2��Create Graph\n");
        printf("    choice 3��Depth First Search\n");
        printf("    choice 4��breadth First Search\n");
        printf("    choice 0��exit\n\n");
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
                printf("ͼ��������ȱ���Ϊ: ");
                TraverseGraph(G);
                break;
            case 4:
                printf("ͼ�Ĺ�����ȱ���Ϊ��");
                TraverseGraph(G);
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("ERROR����\n");
                exit(0);
                break;
        }
    }
    return 0;
}

void init(Graph *G)   //��ʼ���ڽӾ���
{
    int i,j;
    printf("������ͼ�Ķ�������ͱ�����");
    scanf("%d %d",&(G->vexnum),&(G->arcnum));//����ͼ�Ķ�������ͱ���
    for(i=0;i<G->vexnum;i++)              //��ʼ��
    {
        for(j=0;j<G->vexnum;j++)
        {
            G->arcs[i][j]=INFINITY;
        }
    }
    printf("ͼ�ĳ�ʼ���ɹ�\n");
}

int LocateVertex(Graph *G,VertexType v)  //���Ҳ����ض����λ��
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

int createUDG(Graph *G)  //����һ������ͼ
{
    int i,j,k,weight;
    VertexType v1,v2;
    for(i=0;i<G->vexnum;i++)
    {
        printf("������ͼ�ĵ� %d ���㣺",i+1);
        getchar();
        scanf("%c",&(G->vertex[i]));     //����ͼ�Ķ��㼯
    }
    for(k=0;k<G->arcnum;k++)
    {
        printf("��ֱ�����ͼ�ĵ� %d ���ߵ����������Ȩֵ",k+1);
        getchar();
        scanf("%c %c %d",&v1,&v2,&weight);//����һ���ߵ��������㡢Ȩֵ
        i=LocateVertex(G,v1);
        j=LocateVertex(G,v2);
        G->arcs[i][j]=weight;     //��������֮��Ĺ�ϵ
        G->arcs[j][i]=weight;
    }
    return OK;
}

void DepthFirstSearch(Graph G, int i)   //ͼ��������ȱ���
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
    //�����������±�Ϊv�Ķ���֮���бߵĶ��㣬�������������е��±�
    for(int i = 0; i<G.vexnum; i++){
        if( G.arcs[v][i].adj ){
            return i;
        }
    }
    return -1;
}

int NextAdjVex(MGraph G,int v,int w)
{
    //��ǰһ������λ��w����һ��λ�ÿ�ʼ������֮���бߵĶ���
    for(int i = w+1; i<G.vexnum; i++){
        if(G.arcs[v][i].adj){
            return i;
        }
    }
    return -1;
}

//��������ĺ���
void visitVex(MGraph G, int v)
{
    printf("%d ",G.vexs[v]);
}

//��ʼ������
void InitQueue(Queue ** Q){
    (*Q)=(Queue*)malloc(sizeof(Queue));
    (*Q)->next=NULL;
}

//����Ԫ��v������
void EnQueue(Queue **Q,VertexType v){
    Queue * element=(Queue*)malloc(sizeof(Queue));
    element->data=v;
    Queue * temp=(*Q);
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=element;
}

//��ͷԪ�س�����
void DeQueue(Queue **Q,int *u){
    (*u)=(*Q)->next->data;
    (*Q)->next=(*Q)->next->next;
}

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue *Q){
    if (Q->next==NULL) {
        return true;
    }
    return false;
}

//�����������
void BFSTraverse(MGraph G)
   {
    int v;
    //��������ǵ�visit�����ʼ��Ϊfalse
    for( v = 0; v < G.vexnum; ++v)
    {
        visited[v] = false;
    }
    //����ÿ�����Ϊfalse�Ķ���������������������
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
    for (i=0; i<G.vexnum; i++)   //��ʼ�����ʱ�־����
        visited[i] = FALSE;

    for (i=0; i<G.vexnum; i++)//ѭ������������ȱ�����ͨ��ͼ�Ĳ�������ͼG����ͨͼ����˵���ִֻ��һ��
    {
        if (!visited[i])
            DepthFirstSearch(G, i);
    }
    printf("\n");
}
