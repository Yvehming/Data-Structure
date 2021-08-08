#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 100
#define FALSE 0
#define TRUE 1


typedef struct Graph
{
	int a[100][100];
}Graph;


void Create(Graph *s,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			//cin>>s->a[i][j];
			scanf("%d",&s->a[i][j]);
		}
	}
}

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

//void DepthFirstSearch(Graph *s,int i,int n,int visit[])
//{
//	int k;
//	visit[i]=1;
//	for(k=0;k<n;k++)
//	{
//		if(!visit[k]&&s->a[i][k]==1)
//		{
//			DepthFirstSearch(s,k,n,visit);
//		}
//	}
//}

void BreadthFirstSearch(Graph *s,int i,int n,int visit[])
{
	int k,x;
	SeqQueue Q;
	visit[i]=1;
    Init_Queue(&Q);
    Enter_Queue(&Q,i);
    while(Q.front!=Q.rear)
    {
        Delete_Queue(&Q,&x);
        for(i=0;i<n;i++)
        {
            if(s->a[x][i]==1&&visit[i]==0)
            {
                Enter_Queue(&Q,i);
                visit[i]=1;
            }
        }
    }

}

void MakeVisit(Graph *s,int visit[],int n)
{
	int i,flag=0;
	for(i=0;i<n;i++)
	visit[i]=0;
	for(i=0;i<n;i++)
	{
		if(!visit[i])
		{
			flag++;
			//DepthFirstSearch(s,i,n,visit);
			BreadthFirstSearch(s,i,n,visit);
		}
	}
    printf("%d\r\n",flag);
}

int main()
{
	int n,visit[100];
	Graph *s=NULL;
	s=(Graph*)malloc(sizeof(Graph));
	scanf("%d",&n);
	Create(s,n);
	MakeVisit(s,visit,n);
}

