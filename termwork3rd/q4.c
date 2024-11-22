#include <stdio.h>
#include <stdlib.h>
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
  printf("\n");
  while (head != NULL)
  {
    printf("%d ", head->data);
    head = head->next;
  }
}

void multiply(node *head)
{
  int target;
  printf("\ninput the target value");
  scanf("%d",&target);
  
}

int main()
{
  node *head = NULL;
  int ch;
  do
  {
    printf("\ninput the choice:\n1-create a link\n2-display\n3-revrese the linked list\n");
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
      multiply(head);
      break;
    }

  } while (ch != 0);
}