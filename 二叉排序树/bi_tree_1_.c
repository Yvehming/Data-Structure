#include "stdio.h"
#include "stdlib.h"


typedef struct BiTNode
{
    int key;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BSTNode,*BSTree;

int a[1000],b[1000];

void InsertBST(BSTree *bst, int key)
{
    BSTree s;
    if (*bst == NULL)
    {
        s = (BSTree)malloc(sizeof(BSTNode));
        s->key = key;
        s->lchild = NULL;
        s->rchild = NULL;
        *bst = s;
    }
    else if (key<(*bst)->key)
        InsertBST(&((*bst)->lchild),key);
    else if (key>(*bst)->key)
        InsertBST(&((*bst)->rchild),key);
}

void InOrder(BSTree root)
{
    static int i=0;
    if(root!=NULL)
    {
        InOrder(root->lchild);
        printf("%d ",root->key);
        a[i++]=root->key;
        InOrder(root->rchild);
    }
//    if(root==NULL)
//        printf("# ");
}

void  PostOrder(BSTree root)
/* 后序遍历二叉树，root为指向二叉树(或某一子树)根结点的指针*/
{
    static int i=0;
	if(root!=NULL)
	{
		PostOrder(root ->lchild); /*后序遍历左子树*/
		PostOrder(root ->rchild); /*后序遍历右子树*/
		printf("%d ",root->key);
		b[i++]=root->key;
	}
//	if(root==NULL)
//        printf("#");
}

void  PreOrder(BSTree root)
/* 前序遍历二叉树，root为指向二叉树(或某一子树)根结点的指针*/
{
	if(root!=NULL)
	{
		printf("%d ",root->key);
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
	if(root==NULL)
        printf("# ");
}


void CreateBST(BSTree *bst,int num[],int len)
{
    int key,i;
    *bst= NULL;
//    scanf("%d",&key);
//    while(key!=0)
//    {
//        InsertBST(bst,key);
//        scanf("%d",&key);
//    }
    for(i=0;i<len;i++)
    {
        InsertBST(bst,num[i]);
    }
}

BSTNode *DelBST(BSTree t,int k)
{
    BSTNode *p,*f,*s,*q;
    p=t;
    f=NULL;
    while(p)
    {
        if(p->key==k)
            break;
        f=p;
        if(p->key>k)
            p=p->lchild;
        else
            p=p->rchild;
    }
    if(p==NULL)
        return t;
    if(p->lchild==NULL)
    {
        if(f==NULL)
            t=p->rchild;
        else if(f->lchild==p)
            f->lchild=p->rchild;
        else
            f->rchild=p->rchild;
        free(p);
    }
    else
    {
        q=p;
        s=p->lchild;
        while(s->rchild)
        {
            q=s;
            s=s->rchild;
        }
        if(q==p)
            q->lchild=s->lchild;
        else
            q->rchild=s->lchild;
        p->key=s->key;
        free(s);
    }
    return t;
}

int Find_Number(BSTree t,int k)
{
    static int i=0;
    i++;
    if(t==NULL)
    return -1;
    else if(t->key==k)
        return i;
    else if(t->key>k)
        return Find_Number(t->lchild,k);
    else
        return Find_Number(t->rchild,k);

}


int main(void)
{
    BSTree bi,del_bi;
    int num[1000],num_delete,i=0,len,k,y;
    while(1)
    {
        scanf("%d",&num[i++]);
        if(num[i-1]==0)
            break;
    }
    len=i-1;
    scanf("%d",&num_delete);
    scanf("%d",&y);
    CreateBST(&bi,num,len);
    PreOrder(bi);
    printf("\r\n");
    del_bi=DelBST(bi,num_delete);
    InOrder(del_bi);
    printf("\r\n");
    k=Find_Number(del_bi,y);
    printf("%d\r\n",k);


}


