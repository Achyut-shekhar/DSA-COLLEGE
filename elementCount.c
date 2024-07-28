#include <stdio.h>
int main()
{
    int a[100] = {1, 2, 1, 3, 2, 3};
    int i, j, counted;
    for (i = 0; i < 6; i++)
    {
        counted = 0;
        for (j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                counted = 1;
                break;
            }
        }
        if (counted == 1)
            continue;

        int count = 1;
        for (j = i + 1; j < 6; j++)
        {
            if (a[i] == a[j])
                count++;
        }
        printf("frequency of %d is %d\n", a[i], count);
    }
}