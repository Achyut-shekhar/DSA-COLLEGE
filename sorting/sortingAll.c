#include <stdio.h>

void display(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
}

void bubble(int a[], int n)
{
  int flag;
  for (int i = 0; i < n - 1; i++)
  {
    flag = 0;
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (a[j] > a[j + 1])
      {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
        flag = 1;
      }
    }
    if (flag == 0)
      break;
  }
}

void insertion(int a[], int n)
{
  int temp = 0;
  for (int i = 1; i < n; i++)
  {
    temp = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > temp)
    {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = temp;
  }
}

void selection(int a[], int n)
{
  int min = 0;
  for (int i = 0; i < n - 1; i++)
  {
    min = i;
    for (int j = i + 1; j < n; j++)
    {
      if (a[j] < a[min])
      {
        min = j;
      }
    }
    int temp = a[min];
    a[min] = a[i];
    a[i] = temp;
  }
}
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

void mergesort(int a[], int left, int right)
{
  if (left < right)
  {
    // calculating mid point
    int mid = (left + right) / 2;
    // sort the first half
    mergesort(a, left, mid);
    // sort the second half
    mergesort(a, mid + 1, right);
    // merge the sorted halves
    merge(a, left, mid, right);
  }
}

void merge(int a[], int left, int mid, int right)
{
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // create temp array
  int leftArr[n1], rightArr[n2];

  // copy data to temporary arrays
  for (i = 0; i < n1; i++)
    leftArr[i] = a[left + i];
  for (j = 0; j < n2; j++)
    rightArr[j] = a[mid + 1 + j];

  // merging the temp array
  i = 0;
  j = 0;
  k = left;
  while (i < n1 && j < n2)
  {
    if (leftArr[i] <= rightArr[j])
    {
      a[k] = leftArr[i];
      i++;
    }
    else
    {
      a[k] = rightArr[j];
      j++;
    }
    k++;
  }
  while (i < n1)
  {
    a[k] = leftArr[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    a[k] = rightArr[j];
    j++;
    k++;
  }
}

int main()
{
  int ch = 0;
  int n;
  int a[100];
  printf("\ninput the numberof the element");
  scanf("%d", &n);
  printf("\ninput the value");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }

  do
  {
    printf("\n input the choice");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      display(a, n);
      break;
    case 2:
      bubble(a, n);
      display(a, n);
      break;
    case 3:
      insertion(a, n);
      display(a, n);
      break;
    case 4:
      selection(a, n);
      display(a, n);
      break;
    case 5:
      quick(a, 0, n - 1);
      display(a, n);
      break;
    case 6:
      mergesort(a, 0, n - 1);
      display(a, n);
      break;
    }
  } while (ch != 0);
}