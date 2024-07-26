#include<stdio.h>
int ap(int [],int);
int main()
{
    int a[100]={2,5,6,8};
    int i;
    int diff=a[1]-a[0];
    printf("%d",diff);
   if(ap(a,diff))
   {
    printf("ap");
   }
   else
   printf("not");
}

int ap(int a[],int diff)
{
    int i,j,c=0;
    for(i=1;i<4;i++)
    {  
        if((a[i]-a[i-1])!=diff)
           return 0;
    }
    return 1;

}