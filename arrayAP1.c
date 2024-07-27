#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, sum = 0, *a;
    printf("Enter number of elements of array: ");
    scanf("%d", &n);
    printf("Enter the key for elements of array: ");
    scanf("%d", &k);
    a = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    
    for(int i = k-1 ; i<n; i+=k-1){
            for(int j = i ; j<n ; j++){
                    a[j] = a[j+1];
            }
            n--;   
    }
    printf("Array after deletion is: ");
    for(int i = 0 ; i<n ; i++)
        printf("%d ",a[i]);

    free(a);

    return 0;
}
