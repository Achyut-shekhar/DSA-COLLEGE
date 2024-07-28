#include<stdio.h>
int main()
{
    int a[100]={1,2,3,4,5};
    int i,j,t;
    for(i=0,j=4;i<j;i++,j--)
    {
             t=a[i];
             a[i]=a[j];
             a[j]=t;
    }
    for(i=0;i<5;i++)
    {
        printf("%d",a[i]);
    }
}