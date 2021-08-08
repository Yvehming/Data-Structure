#include "stdio.h"
#include "stdlib.h"
#define MAX_VERTEX_NUM 50
#define MAXSIZE 100
#define FALSE 0
#define TRUE 1
#define SIZE 3000

typedef struct Data
{
    int data[MAX_VERTEX_NUM];
    int len;
}Data;

typedef enum {DG,DN,UDG,UDN}GraphKind;
typedef int VertexData;

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
}ArcNode;

//顶点数据
typedef struct VertexNode
{
    VertexData data;
    int indegree;
    ArcNode *firstarc;
}VertexNode;

typedef struct
{
    VertexNode vertex[MAX_VERTEX_NUM];
    int vexnum,arcnum;
}AdjList;

typedef struct
{
    int element[MAXSIZE];
    int front;
    int rear;
    int size;
}SeqQueue;

typedef struct
{
    int element[MAXSIZE];
    int top;
    int size;
}SeqStack;

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

void Init_Stack(SeqStack *S)
{
    S->top=-1;
}

int Push(SeqStack *S,int x)
{
    if(S->top==SIZE-1)
        return FALSE;
    else
    {
        S->top++;
        S->element[S->top]=x;
        return TRUE;
    }
}

int Pop(SeqStack *S,int *x)
{
    if(S->top==-1)
        return FALSE;
    else
    {
        (*x)=S->element[S->top];
        S->top--;
        return TRUE;
    }
}

void Create_DN(AdjList *G,int info[][MAX_VERTEX_NUM])
{
    int i,j,k=0;
    Data D;
    for(i=0;i<G->vexnum;i++)
    {
        G->vertex[i].firstarc=NULL;
        G->vertex[i].data=i;
        G->vertex[i].indegree=0;
    }
    for(i=0;i<G->vexnum;i++)
    {
        for(j=0;j<G->vexnum;j++)
        {
            if(info[i][j]!=0)
            {
                ArcNode *s;
                s=(ArcNode*)malloc(sizeof(ArcNode));
                s->adjvex=j;
                s->nextarc=G->vertex[i].firstarc;
                G->vertex[i].firstarc=s;
                G->vertex[j].indegree++;
            }
        }
    }
    //逆序变正序
    for(i=0;i<G->vexnum;i++)
    {
        ArcNode *p,*l;
        p=(ArcNode*)malloc(sizeof(ArcNode));
        l=(ArcNode*)malloc(sizeof(ArcNode));
        l=p=G->vertex[i].firstarc;
        while(p!=NULL)
        {
            D.data[k]=p->adjvex;
            k++;
            p=p->nextarc;
        }
        D.len=k;
//        for(j=0;j<k;j++)
//            printf("%d\r\n",D.data[j]);
        while(l!=NULL)
        {
            l->adjvex=D.data[k-1];
            l=l->nextarc;
            k--;
        }
    }
}

void Tuopu_Sort(AdjList *G)
{
    int i,j,m=0,num=0;
    SeqStack S;
    ArcNode *p;
    Init_Stack(&S);
    for(i=0;i<G->vexnum;i++)
    {
        if(G->vertex[i].indegree==0)
            Push(&S,i);
    }
    while(S.top!=-1)
    {
        Pop(&S,&i);
        printf("%d ",G->vertex[i].data);
        m++;
        p=G->vertex[i].firstarc;
        while(p!=NULL)
        {
            i=p->adjvex;
            G->vertex[i].indegree--;
            if(G->vertex[i].indegree==0)
            {
                Push(&S,i);
            }
            p=p->nextarc;
        }
    }



}

int main(void)
{
    int i,j,n,adj_info[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    AdjList *G=NULL,*G1=NULL;
    G=(AdjList*)malloc(sizeof(AdjList));
    scanf("%d",&n);
    G->vexnum=n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&adj_info[i][j]);
    Create_DN(G,adj_info);
    Tuopu_Sort(G);
    printf("\r\n");
}






