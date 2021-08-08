#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define SIZE 3000
#define TRUE 1
#define FALSE 0

typedef struct
{
    char elem[SIZE];
    int top;
}SeqStack;

void Init_Stack(SeqStack *S)
{
    S->top=-1;
}

int Push(SeqStack *S,char x)
{
    if(S->top==SIZE-1)
        return FALSE;
    else
    {
        S->top++;
        S->elem[S->top]=x;
        return TRUE;
    }
}

int Pop(SeqStack *S,char *x)
{
    if(S->top==-1)
        return FALSE;
    else
    {
        (*x)=S->elem[S->top];
        S->top--;
        return TRUE;
    }
}

int main(void)
{
    char s[SIZE],str1[SIZE],str2[SIZE],data;
    int i=0,j;
    SeqStack s1;
    Init_Stack(&s1);
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='&')
        {
           memcpy(str1,s,i);
           str1[i]='\0';
        }
    }
    //puts(str1);
    for(i=0;i<strlen(str1);i++)
    {
        Push(&s1,str1[i]);
    }
    for(i=strlen(str1)+1;s[i]!='@';i++)
    {
        Pop(&s1,&data);
        if(s[i]!=data)
        {
            printf("no");
            break;
        }
    }
    if(s[i]=='@')
        printf("%d\r\n",strlen(str1));
    //printf("OK");
}
