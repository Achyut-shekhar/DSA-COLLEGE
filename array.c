#include<stdio.h>
int delete(int [],int,int);
void shift(int[],int,int,int);
int main()
{
    int a[100];
    int n,i,k;
    printf("input the limit: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("input the k: ");
    scanf("%d",&k);
    n=delete(a,n,k);
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }

}
int delete(int a[],int n,int k)
{
    int ind,i;
    for(i=1;i*k-1<n-1;i++)
    {
        ind=(i*k)-1;
        if(ind<n)
        {
            printf("%d\n",ind);
            shift(a,ind,n,k);
            n--;
            i--;
        }
    }
    return n;
}
void shift(int a[],int ind,int n,int k)
{  
    int i;
    for(i=ind;i<n-1;i++)
       { a[i]=a[i+1];
       }
}