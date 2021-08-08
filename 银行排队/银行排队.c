#include "stdio.h"

#define MAXSIZE 100
#define FALSE 0
#define TRUE 1
//ѭ�����нṹ��
typedef struct
{
    int element[MAXSIZE];
    int front;
    int rear;
    int size;
}SeqQueue;

void Init_Queue(SeqQueue *Q)
{
    Q->front=Q->rear=0;
    Q->size = 0;
}

//���ݴ�������ð������
void bubble_sort(int arr[], int len) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int Get_Head(SeqQueue *Q)
{
    if(Q->front==Q->rear)
        return -1;
    else
    {
        return Q->element[Q->front];
    }
}
//���
int Enter_Queue(SeqQueue *Q,int x)
{
    if((Q->rear+1)%MAXSIZE==Q->front)//������
        return FALSE;
    else
    {
        Q->element[Q->rear]=x;
        Q->rear=(Q->rear+1)%MAXSIZE;
        Q->size++;
        return TRUE;
    }
}

//
int Enter_Queue_in_Sequence(SeqQueue *Q,int x)
{
    int i,j=0,a[100];
    if((Q->rear+1)%MAXSIZE==Q->front)//������
        return FALSE;
    else
    {
        Q->element[Q->rear]=x;
        Q->rear=(Q->rear+1)%MAXSIZE;
        Q->size++;
        for(i=Q->front;i<Q->front+Q->size;i++)
        {

            a[j]=Q->element[i];
            j++;
        }
        bubble_sort(a,Q->size);
        j=0;
        for(i=Q->front;i<Q->front+Q->size;i++)
        {
            Q->element[i]=a[j];
            j++;
        }
        return TRUE;
    }
}
//����
int Delete_Queue(SeqQueue *Q,int *x)
{
    if(Q->front==Q->rear)
        return FALSE;
    else
    {
        *x=Q->element[Q->front];
        Q->front=(Q->front+1)%MAXSIZE;
        Q->size--;
        return TRUE;
    }
}

double Wait_time(int m,int total)
{
    SeqQueue Q;
    int arri=0,stay=0,time=0;//����ʱ�䣬�ȴ�ʱ�䣬�ܵȴ�ʱ��
    int temp,oldArri;
    Init_Queue(&Q);
    while(total)
    {
        scanf("%d",&arri);
        scanf("%d",&stay);
        while(Q.size != 0 && Get_Head(&Q) <= arri)//���ڷǿգ�
        //���Ҷ����е�һ���뿪���˵��뿪ʱ��С�ڵ�ǰ�����˵ĵ���ʱ��
        {
            Delete_Queue(&Q , &temp);
        }
        if(Q.size < m)//����û����
        {
            Enter_Queue_in_Sequence(&Q , arri+stay);//�ѵ�ǰ��������ӣ���ӵ����뿪ʱ�䣩
        }
        else
        {
            time = time+Get_Head(&Q)-arri;
            oldArri = Get_Head(&Q);
            Delete_Queue(&Q , &temp);
            Enter_Queue_in_Sequence(&Q , oldArri+stay);
        }
        total--;
    }
    return time;
}

int main(void)
{
    int m, total,i=1;
    //scanf("%d",&m);
    //scanf("%d",&total);
    while(scanf("%d%d",&m,&total)!=EOF)
        printf("%.2f\r\n",Wait_time(m,total)/total);


}


