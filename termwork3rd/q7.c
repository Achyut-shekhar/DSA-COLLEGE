#include <stdio.h>
#include <string.h>

#define MAX 100 // Maximum number of names
#define LEN 100 // Maximum length of a name

// Function to swap two strings
void swap(char a[], char b[])
{
  char temp[LEN];
  strcpy(temp, a);
  strcpy(a, b);
  strcpy(b, temp);
}

// Partition function for Quick Sort
int partition(char arr[][LEN], int low, int high)
{
  char pivot[LEN];
  strcpy(pivot, arr[high]); // Choosing the last element as the pivot
  int i = low - 1;

  for (int j = low; j < high; j++)
  {
    if (strcmp(arr[j], pivot) < 0)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

// Quick Sort function
void quickSort(char arr[][LEN], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high); // Partition index

    // Recursively sort elements before and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main()
{
  int n;
  char names[MAX][LEN];

  printf("Enter the number of names: ");
  scanf("%d", &n);

  getchar(); // To consume the newline character after the number input

  printf("Enter the names:\n");
  for (int i = 0; i < n; i++)
  {
    fgets(names[i], LEN, stdin);
    // Remove the newline character added by fgets
    names[i][strcspn(names[i], "\n")] = '\0';
  }

  // Sorting names using Quick Sort
  quickSort(names, 0, n - 1);

  printf("\nSorted names:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%s\n", names[i]);
  }

  return 0;
}
