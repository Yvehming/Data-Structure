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
//        printf("%d ",root->key);
        a[i++]=root->key;
        InOrder(root->rchild);
    }
}

void  PostOrder(BSTree root)
/* 后序遍历二叉树，root为指向二叉树(或某一子树)根结点的指针*/
{
    static int i=0;
	if(root!=NULL)
	{
		PostOrder(root ->lchild); /*后序遍历左子树*/
		PostOrder(root ->rchild); /*后序遍历右子树*/
//		printf("%d ",root->key);
		b[i++]=root->key;
	}
//	if(root==NULL)
//        printf("#");
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

int main(void)
{
    BSTree bi;
//    bi=(BStree)malloc(sizeof(BSTNode));

    int num[1000],num1[1000],i=0,len,k=1;
//    for(i=0;scanf("%d",&num[i])!=EOF;i++);
    while(scanf("%d",&k)!=EOF)//回车后ctr+z结束
    {
        num[i++]=k;
        //i++;
    }
    len=i;
//    printf("%d\r\n",len);
//    for(i=0;i<len;i++)
//        printf("%d ",num[i]);

    for(i=0;i<len;i++)
    {
        num1[i]=num[len-1-i];
    }
//    for(i=0;i<len;i++)
//        printf("%d ",num1[i]);
    CreateBST(&bi,num1,len);

    InOrder(bi);
    PostOrder(bi);
//    for(i=0;i<len;i++)
//        printf("%d ",a[i]);
//    for(i=0;i<len;i++)
//        printf("%d ",b[i]);
    for(i=0;i<len;i++)
    {
        if(b[i]!=num[i])
            //printf("false\r\n");
            {
               k=0;
               break;
            }

    }
    if(i==len)
        printf("true\r\n");
    if(k==0&&i!=len)
        printf("false\r\n");
}
