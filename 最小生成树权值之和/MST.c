#include "stdio.h"
#include "stdlib.h"
#define MAX_VERTEX_NUM 50
#define MAXSIZE 100
#define FALSE 0
#define TRUE 1

typedef enum {DG,DN,UDG,UDN}GraphKind;
typedef int VertexData;
typedef struct ArcNode
{
    int adj;
}ArcNode;

typedef struct
{
    VertexData vertex[MAX_VERTEX_NUM];
    ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum,arcnum;
}AdjMatrix;

typedef struct
{
    int adjvex;
    int lowcost;
}CLOSEDGE;


typedef struct
{
    int element[MAXSIZE];
    int front;
    int rear;
    int size;
}SeqQueue;
//队列初始化
void Init_Queue(SeqQueue *Q)
{
    Q->front=Q->rear=0;
    Q->size = 0;
}

//入队
int Enter_Queue(SeqQueue *Q,int x)
{
    if((Q->rear+1)%MAXSIZE==Q->front)//队满了
        return FALSE;
    else
    {
        Q->element[Q->rear]=x;
        Q->rear=(Q->rear+1)%MAXSIZE;
        return TRUE;
    }
}

//出队
int Delete_Queue(SeqQueue *Q,int *x)
{
    if(Q->front==Q->rear)
        return FALSE;
    else
    {
        *x=Q->element[Q->front];
        Q->front=(Q->front+1)%MAXSIZE;
        return TRUE;
    }
}

//创建有向网
int Create_UDN(AdjMatrix *G)
{
    int i,j,k,l;
    VertexData v1,v2;
    scanf("%d",&G->vexnum);
    scanf("%d",&G->arcnum);
//    printf("%d %d",G->vexnum,G->arcnum);
    for(i=0;i<G->vexnum;i++)
        for(j=0;j<G->vexnum;j++)
            G->arcs[i][j].adj=65536;
    for(i=0;i<G->arcnum;i++)
    {
        scanf("%d",&j);
        scanf("%d",&k);
        scanf("%d",&l);
        G->arcs[j-1][k-1].adj=l;
        G->arcs[k-1][j-1].adj=l;
    }
}
int Minium(CLOSEDGE closedge[],int num)
{
    int i,j,k;
    for(i=0;i<num;i++)
    {
        if(closedge[i].lowcost!=0)
        {
            j=closedge[i].lowcost;
            k=i;
            break;
        }
    }
    for(i=0;i<num;i++)
    {
        if(closedge[i].lowcost!=0)
        {
            if(j>closedge[i].lowcost)
            {
                j=closedge[i].lowcost;
                k=i;
            }
        }
    }
    return k;
}
//最小生成树
void Mini_Span_Tree(AdjMatrix *gn,int u,int n)
{
    int i,e,v,uu,sum=0;
    CLOSEDGE closedge[MAX_VERTEX_NUM];
    closedge[u].lowcost=0;
    for(i=0;i<gn->vexnum;i++)
    {
        if(i!=u)
        {
            closedge[i].adjvex=u;
            closedge[i].lowcost=gn->arcs[u][i].adj;
        }
    }
//    for(i=1;i<=gn->vexnum;i++)
//        printf("%d ",closedge[i].lowcost);
    for(e=1;e<=gn->vexnum-1;e++)
    {
        v=Minium(closedge,n);
//        printf("%d\r\n",v);
        uu=closedge[v].adjvex;
        printf("%d-%d:%d\r\n",uu+1,v+1,gn->arcs[uu][v].adj);
        sum+=gn->arcs[uu][v].adj;
        closedge[v].lowcost=0;
        for(i=1;i<=gn->vexnum;i++)
        {
            if(gn->arcs[v][i].adj<closedge[i].lowcost)
            {
                closedge[i].lowcost=gn->arcs[v][i].adj;
                closedge[i].adjvex=v;
            }
        }
    }
    printf("%d\r\n",sum);
}


int main(void)
{
    int i=0;
    AdjMatrix *G=NULL;
    G=(AdjMatrix*)malloc(sizeof(AdjMatrix));
    Create_UDN(G);
//    for(i=1;i<=G->vexnum;i++)
//    {
//        for(j=1;j<=G->vexnum;j++)
//            printf("%d ",G->arcs[i][j].adj);
//        printf("\r\n");
//    }


    Mini_Span_Tree(G,i,G->vexnum);
}





