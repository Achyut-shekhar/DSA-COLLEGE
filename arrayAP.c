#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n , k , c = 0,sum = 0,max=0,*a;
    
    printf("Enter number of elements of array: ");
    scanf("%d",&n);
    
    printf("Enter the key for elements of array: ");
    scanf("%d",&k);
    
    a = (int*)malloc(n*sizeof(int));
    
    for(int i = 0 ; i < n ; i ++){
            scanf("%d",a+i);
    }
    
    for(int i = 0 ; i < k ; i++)
        max += a[i];
    
    sum = max;
        
    for(int i = k ; i < n ; i ++){
        sum += a[i];
        sum -= a[i-k];

        if(sum>max)
            max = sum;
    }
    
    printf("Max sum is: %d",max);
    
    free(a);

    return 0;
}