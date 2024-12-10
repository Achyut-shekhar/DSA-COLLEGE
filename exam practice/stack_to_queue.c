#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node
{
  int data;
  struct node *next;
} node;

// Function to create a linked list
node *create(node *head)
{
  int val, ch = 0;
  node *newnode = NULL, *temp = NULL;
  while (1)
  {
    printf("\nInput the data: ");
    scanf("%d", &val);
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = temp;
    temp = newnode;

    printf("If you want to end, press '0': ");
    scanf("%d", &ch);
    if (ch == 0)
      break;
  }
  return temp;
}

// Function to display a linked list
void display(node *head)
{
  while (head != NULL)
  {
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

void queue(node *head)
{

  if (head == NULL)
    return;

  queue(head->next);
  printf("%d->", head->data);
}

int main()
{
  node *head1 = NULL, *head2 = NULL, *mergedHead = NULL;

  printf("Create the 1st singly linked list:\n");
  head1 = create(head1);
  printf("First linked list: ");
  display(head1);
  printf("printed as a stack\n");
  queue(head1);

  return 0;
}
