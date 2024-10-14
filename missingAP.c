#include <stdio.h>
int main()
{
    int i, j;
    int a[5] = {1,3,10,11,13};
    int ap_diff = a[1] - a[0];
        for (i = 0; i < 5; i++)  
    {
        int expected = a[i] + ap_diff;
        while (expected < a[i + 1])  
        {   
            printf("%d->%d\n",a[i+1] ,expected);
            expected += ap_diff;
        }
    }
    
}