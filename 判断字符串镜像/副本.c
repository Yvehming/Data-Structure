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
    int i=0;
    char ch,x;
    SeqStack s1;
    Init_Stack(&s1);
    ch=getchar();
    while(ch!='&')
    {
       Push(&s1,ch);
       ch=getchar();
    }
    i=0;
    while(ch!='@')
    {
       Pop(&s1,&x);
       ch=getchar();
      // putchar(ch);
       //putchar(x);
       if(x!= ch &&ch != '@')
       {
           printf("no");
           break;
       }
        else
            i++;
    }
    if(ch == '@' )
        printf("%d\r\n",i-1);


}
