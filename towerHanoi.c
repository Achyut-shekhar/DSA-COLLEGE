#include<stdio.h>
void tower(int,char,char,char);
int main()
{
    int n=2;
    char a='p',b='q',c='r';
    tower(n,a,b,c);
}
void tower(int n,char a,char b,char c)
{
    if(n==1)
    {
        printf("move is %c to %c\n",a,c);
    }
    else{
    tower(n-1,a,c,b);
    printf("move is %c to %c\n",a,c);
    tower(n-1,b,a,c);
    }
}
