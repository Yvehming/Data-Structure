#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define MAXSIZE  1000
//�ݹ齨������
void build(int n, char* ldr, char* lrd, char* s)
{
    int p;
	if(n == 0)
    {

    }
    else
    {
        p = strchr(ldr, lrd[n-1]) - ldr;//�Ҹ������s1�е�λ��
        s[0] = lrd[n-1];//�Ѹ������ӵ���ǰ��
        build(p, ldr, lrd, s+1);//�ݹ鹹�����������������
        build(n-p-1, ldr+p+1, lrd+p, s+p+1);//�ݹ鹹�����������������
    }
}

int main(void)
{
    char s[MAXSIZE],s1[MAXSIZE],s2[MAXSIZE],\
    target[MAXSIZE],left[MAXSIZE],right[MAXSIZE];
    int pos,i,j;
    gets(s);
    for(i = 0;s[i] != ' ';i++);
    memcpy(s1,s,i);
    memcpy(s2,s+i+1,strlen(s)-i);
    //puts(s1);
    //printf("\r\n");
    //puts(s2);
    build(strlen(s1),s1,s2,target);
    target[strlen(s1)]='\0';
    puts(target);

}
