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
	//�����������һ�Ŷ�����,���磺 ����ABD.G...CE..F..
	char ch;
	ch = getchar();
    if(ch=='#')
    {
        *bt=NULL;
    }

    else
	{
		*bt=(BiTree)malloc(sizeof(BiTNode)); //����һ���½��
        (*bt)->data=ch;
        CreateBiTree(&((*bt)->RChild)); //����������
        CreateBiTree(&((*bt)->LChild)); //����������
        //CreateBiTree(&((*bt)->RChild)); //����������
	}
}

void Visit(char ch)
{
	printf("%c",ch);
}

void  PreOrder(BiTree root)
/*�������������, rootΪָ�������(��ĳһ����)������ָ��*/
{
	if (root!=NULL)
	{
		Visit(root ->data);  /*���ʸ����*/
		PreOrder(root ->LChild);  /*�������������*/
		PreOrder(root ->RChild);  /*�������������*/
	}
}

void  InOrder(BiTree root)
/*�������������, rootΪָ�������(��ĳһ����)������ָ��*/
{
	if (root!=NULL)
	{
		InOrder(root ->LChild);   /*�������������*/
		Visit(root ->data);        /*���ʸ����*/
		InOrder(root ->RChild);   /*�������������*/
	}
}

void  PostOrder(BiTree root)
/* ���������������rootΪָ�������(��ĳһ����)������ָ��*/
{
	if(root!=NULL)
	{
		PostOrder(root ->LChild); /*�������������*/
		PostOrder(root ->RChild); /*�������������*/
		Visit(root ->data);       /*���ʸ����*/
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
