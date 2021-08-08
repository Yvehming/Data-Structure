#include "stdio.h"
#include "malloc.h"
#include "string.h"

typedef struct Node
{
    int data;
    struct Node *next;
}Node,*Linklist;

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

void bubble_sort(int arr[], int len) {
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

int main(void)
{
    Linklist pa,h;
    int a[100],i=0;
    Node *s;
    pa=(Linklist)malloc(sizeof(Node));
    pa->next=NULL;
    CreateFromTail(pa);
    h=pa;
    while(h->next)
    {
        a[i]=h->next->data;
        i++;
        h=h->next;
    }
    bubble_sort(a,ListLength(pa));
    for(i=1;i<ListLength(pa);i++)
    {
        printf("%d ",a[i]);
    }
}


