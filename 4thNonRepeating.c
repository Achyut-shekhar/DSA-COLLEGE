//print the 4th non repeating element in the array
#include<stdio.h>
int main()
{
    int a[100]={1,8,1,9,8,4,3,6,1,7,3};
    int i,j,counted,rep=0;
    for(i=0;i<11;i++)
    {    counted=0;
        for(j=0;j<11;j++)
        {
            if(a[i]==a[j] && i!=j && i<j)
            {
            counted++;
            break;
            }
        }
        if(counted==0)
        rep++;

        if(rep==4)
        {printf("4th non repeating %d",a[i]); //in this remenber to print a[i] rather than rep
        break;}
    }
    
}