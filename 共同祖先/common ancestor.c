#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 100

typedef struct Node
{
	char data;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode, *BiTree;

BiTree Create(char *pre,char *mid,int len)
{
	if(len==0)
        return NULL;
	int i;
	BiTree p;
	p=(BiTNode*)malloc(sizeof(BiTNode));
	p->data=pre[0];
	for(i=0;i<len;i++)
	{
		if(pre[0]==mid[i])
            break;
	}
	p->LChild=Create(pre+1,mid,i);
	p->RChild=Create(pre+i+1,mid+i+1,len-i-1);
	return p;
}

void Search(BiTNode *T,BiTNode *node)
{
	if(T!=NULL)
	{
		if(T->data==node->data)
            node=T;
		Search(T->LChild,node);
		Search(T->RChild,node);
	}
}

BiTree search(BiTree T,BiTree node1,BiTree node2)
{
	if(T==NULL)
        return NULL;
	if(T->data==node1->data||T->data==node2->data)
        return T;
	BiTree left=search(T->LChild,node1,node2);
	BiTree right=search(T->RChild,node1,node2);
	if(left&&right)
        return T;
	if(left)
        return left;
	if(right)
        return right;
    return NULL;
}

BiTree GetParent(BiTree T,BiTree node1,BiTree node2)
{
	BiTree p=search(T,node1,node2);
	return p;
}

int main()
{
    int len;
    char pre[MAX],mid[MAX];
    char a,b;
    BiTree T=NULL;
    BiTree node1=NULL,node2=NULL,node=NULL;
    T=(BiTNode*)malloc(sizeof(BiTNode));
    node1=(BiTNode*)malloc(sizeof(BiTNode));
	node2=(BiTNode*)malloc(sizeof(BiTNode));
	node=(BiTNode*)malloc(sizeof(BiTNode));
    gets(pre);
    gets(mid);
    a=getchar();
    b=getchar();
//    putchar(a);
//    putchar(b);
    len=strlen(pre);
    T=Create(pre,mid,len);
	node1->data=a;
	node2->data=b;
	Search(T,node1);
	Search(T,node2);
	node=GetParent(T,node1,node2);
	if(node!=NULL&&node->data!=T->data)
        putchar(node->data);
	else
        printf("NULL");

}

