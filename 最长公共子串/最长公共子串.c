#include "stdio.h"
#include "string.h"
#define MAXSIZE 100

typedef struct
{
    char ch[MAXSIZE];
    int len;
}SString;

void Get_Common(char str1[],char str2[],char *str3)
{
    int i,j,k,max=0,start=-1;
    for(i=0;i<strlen(str1);i++)
    {
        for(j=0;j<strlen(str2);j++)
        {
            if(str1[i]==str2[j])
            {
                for(k=0;(str1[i+k]==str2[j+k]&&str2[j+k]!='\0'&&str1[i+k]!='\0');k++);
                if(max<k)
                {
                    max=k;
                    start=i;
                }
            }
        }
    }
    if(start==-1)
        strcpy(str3,"no");
    else
    {
        memcpy(str3,&str1[start],max);
        str3[max] = '\0';
    }
}
int main(void)
{
    char s1[MAXSIZE],s2[MAXSIZE],s3[MAXSIZE];
    gets(s1);
    gets(s2);
    Get_Common(s1,s2,s3);
    puts(s3);
    return 0;
}

