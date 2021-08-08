#include "stdio.h"
#include "malloc.h"
#include "string.h"

typedef struct Node
{
    int data;
    struct Node *next;
}Node,*Linklist;

typedef struct DNode
{
    int data;
    struct DNode  *prior,*next;
}DNode, *DoubleList;

void init_linklist(Linklist *l)/*对单链表进行初始化*/
{
	*l=(Linklist) malloc(sizeof(Node)); /*申请结点空间*/
	(*l)->next=NULL;                   /*置为空表*/
}

void CreateFromTail(Linklist L)
{
    Node *r,*s;
    int flag=1,d,num=1;
    float c;
    r=L;
    //scanf("%d",&num);
    //printf("%d\r\n",num);
    while(num!=0)
    {
        scanf("%d",&num);
        s=(Node*)malloc(sizeof(Node)); //建立新结点s
        s->data=num;
        r->next=s;
        r=s;
    }
        //printf("OK\r\n");
        r->next=NULL;

}


void DisplayLinklist(Linklist L)
{
    Linklist p;
    p=L;
    while(p->next)
    {
        printf("%d ",p->next->data);
        p=p->next;
    }
}

int ListLength(Linklist L)
{
    Node *p;
    p=L->next;
    int j=0;
    while(p!=NULL)
    {
        p=p->next;
        j++;
    }
    return j;
}

void Sort(int arr[], int len) {
    int i, j, temp;
    //float temp1;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                //temp1=b[j];
                arr[j] = arr[j + 1];
                //b[j] = b[j+1];
                arr[j + 1] = temp;
                //b[j+1]=temp1;
            }
}

void Create_Double_Linked_List(DoubleList L)
{
    DNode *s,*r,*p;
    int n;
    scanf("%d",&n);
    s=(DNode*)malloc(sizeof(DNode)); //建立新结点s
    s->data=n;
    s->next=L->next;
    s->prior=L;
    L->next=s;
    L->prior=s;
    p=s;
    scanf("%d",n);
    while(n)
    {
        if(n>p->data)
        {
            while(1)
            {
                if()
            }
        }
    }



}
int main(void)
{
    DoubleList pa;
    pa=(DoubleList)malloc(sizeof(DNode));
    pa->next=pa;
    pa->prior=pa;
    pa->data=0;
    Create_Double_Linked_List(pa);
    while(pa->next->data!=0)
    {
        printf("%d\r\n",pa->next->data);
        pa=pa->next;
    }
}
