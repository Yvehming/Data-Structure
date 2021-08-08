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

int num,count;
void CreateFromTail(Linklist L)
{
    Node *r,*s;
    int flag=1;
    r=L;
    scanf("%d",&num);
    scanf("%d",&count);
    //printf("%d\r\n",num);
    while(flag<=num)
    {

        s=(Node*)malloc(sizeof(Node)); //建立新结点s
        s->data=flag;
        r->next=s;
        r=s;
        flag++;
    }
        //printf("OK\r\n");
        r->next=L->next;
}




void DisplayLinklist(Linklist L)
{
    Linklist p;
    p=L;
    while(p->next!=L)
    {
        printf("%d ",p->next->data);
        p=p->next;
    }
}

int main(void)
{
    Linklist pa,q,s;
    int i=1,j;
    pa=(Linklist)malloc(sizeof(Node));
    pa->next=NULL;
    CreateFromTail(pa);
    q=pa;
    j=num;
    //DisplayLinklist(pa);
    //pa=pa->next;
    while(j!=0)
    {
        for(i=1;i<count;i++)
        {
            pa=pa->next;
        }

        //printf("%d\r\n",pa->next->data);
        pa->next=pa->next->next;

        j--;
    }

    printf("%d\r\n",pa->data);
    //printf("%d\r\n",num);

}



