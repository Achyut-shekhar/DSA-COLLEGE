#include <stdio.h>
#include <stdlib.h>
typedef struct link
{
  int data;
  struct link *next;
} link;
void display(link *head)
{
  if (head == NULL)
  {
    printf("empty");
  }
  else
  {
    while (head != NULL)
    {
      printf("%d", head->data);
      head = head->next;
    }
  }
}
void printReverse(link *head)
{
  if (head == NULL)
  {
    return;
  }
//using recursion
  printReverse(head->next);
  printf("\n%d", head->data);
}
int main()
{
  printf("make a linked list");
  link *head = NULL, *temp = NULL;
  link *p;
  int ch;
  while (1)
  {
    p = (link *)malloc(sizeof(link));
    if (p == NULL)
    {
      printf("memory not allocated");
      break;
    }
    else
    {
      printf("\nenter the data");
      scanf("%d", &p->data);
      p->next = NULL;
      if (head == NULL)
      {
        head = temp = p;
      }
      else
      {
        temp->next = p;
        temp = p;
      }
    }
    printf("\nDo you want to continue? Yes-1 No-0: ");
    scanf("%d", &ch);
    if (ch == 0)
    {
      break; // Break from the loop if the user inputs 0
    }
  }
  display(head);
  printReverse(head);
}