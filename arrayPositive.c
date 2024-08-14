//arrange all the positive and negative one side of the array in the same format

#include<stdio.h>
void arrange(int []);
int main()
{
    int a[100]={1,-2,-3,4,-5,6};
    if(a[0]>0)
       arrange(a);
}
void arrange(int a[])
{
    int i,j,k=0,c=0,t;
    for(i=1;i<6;i++)
    {
        if(a[i]<0)
        {
            c++;
        }
        else{
            for(j=i;k<c;k++,j--) //observe this loop carefully and use k
            {
                t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
            }
              k=0; //again making the k=0 so for next positive it will start from 0 to number of negative which is c
        }
    }
    for(i=0;i<6;i++)
    {
        printf("%d\t",a[i]);
    }
}
//make it for if a[0]<0 and whill follow the same rule but with different condition.