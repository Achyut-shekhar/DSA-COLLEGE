#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
int partition(int a[], int lb, int ub)
{
  int pivot = a[lb];
  int start = lb;
  int end = ub;
  // checking start is not greater than end
  while (start < end)
  {
    // in start if value is less than pivot then move forward
    while (a[start] <= pivot)
    {
      start++;
    }
    // in end if value is greater than the pivot then move backward
    while (a[end] > pivot)
    {
      end--;
    }
    // swap if start is less than end
    if (start < end)
    {
      swap(&a[start], &a[end]);
    }
  }
  // if start is greater than end then swap end pivot
  swap(&a[lb], &a[end]);
  return end;
}
void quick(int a[], int lb, int ub)
{
  if (lb < ub)
  {
    int pivot = partition(a, lb, ub);

    quick(a, lb, pivot - 1);
    quick(a, pivot + 1, ub);
  }
}

int main()
{
  int n;
  int a[100];
  printf("\ninput the numberof the element");
  scanf("%d", &n);
  printf("\ninput the value");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  quick(a, 0, n - 1);
  printf("\nSorted array is:");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
}