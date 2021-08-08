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
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum,arcnum;
}AdjMatrix;

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

int LocateVertex(AdjMatrix *G,VertexData v)
{
    int j=-1,k;
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


int Create_UDG(AdjMatrix *G)
{
    int i,j,k;
    VertexData v1,v2;
    scanf("%d",&G->vexnum);
    for(i=0;i<G->vexnum;i++)
        scanf("%d",&G->vertex[i]);//输入顶点值
    for(i=0;i<G->vexnum;i++)
        for(j=0;j<G->vexnum;j++)
            scanf("%d",&G->arcs[i][j]);
}

void BreadthFirstSearch(AdjMatrix *s,int i,int n,int visit[])
{
	int k,x;
	SeqQueue Q;
	visit[i]=1;
    Init_Queue(&Q);
    Enter_Queue(&Q,i);
    while(Q.front!=Q.rear)
    {
        Delete_Queue(&Q,&x);
        printf("%d ",s->vertex[x]);
        for(i=0;i<n;i++)
        {
            if(s->arcs[x][i]==1&&visit[i]==0)
            {
                Enter_Queue(&Q,i);
                visit[i]=1;
            }
        }
    }
}
void MakeVisit(AdjMatrix *s,int visit[],int n)
{
	int i,flag=0;
	for(i=0;i<n;i++)
	visit[i]=0;
	for(i=0;i<n;i++)
	{
		if(!visit[i])
		{
			flag++;
			BreadthFirstSearch(s,i,n,visit);
		}
	}
    //printf("%d\r\n",flag);
}
int main(void)
{
    int i=0,visit[100];
    AdjMatrix *G=NULL;
    G=(AdjMatrix*)malloc(sizeof(AdjMatrix));
    Create_UDG(G);
    MakeVisit(G,visit,G->vexnum);
}



