#include "stdio.h"
#include "stdlib.h"

void ShellInsert(int r[],int len,int delta)
{
    int i,j;
    for(i=1+delta;i<=len;i++)
        if(r[i]<r[i-delta])
        {
            r[0]=r[i];
            for(j=i-delta;j>0&&r[0]<r[j];j-=delta)
            {
                r[j+delta]=r[j];
            }
            r[j+delta]=r[0];
        }
    for(i=1;i<len+1;i++)
        printf("%d ",r[i]);
    printf("\r\n");
}

void ShellSort(int r[],int len,int delta[],int n)
{
    int i;
    for(i=0;i<=n-1;i++)
        ShellInsert(r,len,delta[i]);
}

int main()
{
    int num[1000],delta[1000],i=1,length;
    while(1)
    {
        scanf("%d",&num[i++]);
        if(num[i-1]==0)
            break;
    }
    length=i-2;
    //printf("%d\r\n",length);
    for(i=0;i<3;i++)
        scanf("%d",&delta[i]);
    ShellSort(num,length,delta,3);
    return 0;
}
