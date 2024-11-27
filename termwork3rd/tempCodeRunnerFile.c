#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct node
{
  int data;
  struct node *next;
} node;
node *createlink(node *head)
{
  node *temp = NULL, *newnode = NULL;
  int ch = 0;
  while (1)
  {
    newnode = (node *)malloc(sizeof(node));
    printf("\ninput the data");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL)
    {
      head = temp = newnode;
    }
    else
    {
      temp->next = newnode;
      temp = newnode;
    }
    printf("\nif dont want to continue press 0");
    scanf("%d", &ch);
    if (ch == 0)
      break;
  }
  return head;
}
void display(node *head)
{

  while (head != NULL)
  {
    printf("\n%d", head->data);
    head = head->next;
  }
}
void second_min(node *head)
{
  int min = head->data;
  int SecondMin = min;
  while (head != NULL)
  {
    if (head->data < min)
    {
      SecondMin = min;
      min = head->data;
    }
    else if (head->data > min && SecondMin > head->data)
    {
      SecondMin = head->data;
    }
    head = head->next;
  }
  printf("\nThe Second minimum is %d", SecondMin);
}

int main()
{
  node *head = NULL;
  int ch;
  do
  {
    printf("\n\ninput the choices:\n1-create a link\n2-display a link\n3-find the second minimum");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      head = createlink(head);
      break;
    case 2:
      display(head);
      break;
    case 3:
      second_min(head);
      break;
    }
  } while (ch != 0);
}
