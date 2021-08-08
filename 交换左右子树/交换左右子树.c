#include "stdio.h"
#include "stdlib.h"


typedef struct Node
{
	char data;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode, *BiTree;

void CreateBiTree(BiTree *bt)
{
	//先序遍历生成一颗二叉树,例如： 输入ABD.G...CE..F..
	char ch;
	ch = getchar();
    if(ch=='#')
    {
        *bt=NULL;
    }

    else
	{
		*bt=(BiTree)malloc(sizeof(BiTNode)); //生成一个新结点
        (*bt)->data=ch;
        CreateBiTree(&((*bt)->RChild)); //生成右子树
        CreateBiTree(&((*bt)->LChild)); //生成左子树
        //CreateBiTree(&((*bt)->RChild)); //生成右子树
	}
}

void Visit(char ch)
{
	printf("%c",ch);
}

void  PreOrder(BiTree root)
/*先序遍历二叉树, root为指向二叉树(或某一子树)根结点的指针*/
{
	if (root!=NULL)
	{
		Visit(root ->data);  /*访问根结点*/
		PreOrder(root ->LChild);  /*先序遍历左子树*/
		PreOrder(root ->RChild);  /*先序遍历右子树*/
	}
}

void  InOrder(BiTree root)
/*中序遍历二叉树, root为指向二叉树(或某一子树)根结点的指针*/
{
	if (root!=NULL)
	{
		InOrder(root ->LChild);   /*中序遍历左子树*/
		Visit(root ->data);        /*访问根结点*/
		InOrder(root ->RChild);   /*中序遍历右子树*/
	}
}

void  PostOrder(BiTree root)
/* 后序遍历二叉树，root为指向二叉树(或某一子树)根结点的指针*/
{
	if(root!=NULL)
	{
		PostOrder(root ->LChild); /*后序遍历左子树*/
		PostOrder(root ->RChild); /*后序遍历右子树*/
		Visit(root ->data);       /*访问根结点*/
	}
	if(root==NULL)
        printf("#");
}

int Leaf(BiTree root)
{
    static int num=0;
   if(root!=NULL)
    {
        if(root->LChild==NULL&&root->RChild==NULL)
            num++;
        Leaf(root->LChild);
        Leaf(root->RChild);
    }
    return num;

}
int main(void)
{
    BiTree bt;
    //int x;
    CreateBiTree(&bt);
    printf("%d\r\n",Leaf(bt));
    PostOrder(bt);

}
