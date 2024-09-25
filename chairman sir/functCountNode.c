#include <stdio.h>
#include <stdlib.h>
typedef struct link
{
  int val;
  struct link *next;
} link;
link *makeLink(link *newnode, link *head, link *temp)
{
  int ch;
  while (1)
  {
    newnode = (link *)malloc(sizeof(link));
    if (newnode == NULL)
    {
      printf("Memory allocation failed\n");
      break;
    }
    printf("Enter the data: ");
    scanf("%d", &newnode->val);
    newnode->next = NULL; // Ensure the new node terminates the list

    if (head == NULL)
    {
      head = temp = newnode; // Initialize the head for the first node
    }
    else
    {
      temp->next = newnode; // Link the new node
      temp = newnode;       // Move the temp pointer to the new node
    }

    printf("\nDo you want to continue? Yes-1 No-0: ");
    scanf("%d", &ch);
    if (ch == 0)
    {
      break; // Break from the loop if the user inputs 0
    }
  }
  return head; // Return the head of the list
}

void display(link *head)
{
  printf("\nthe display of the linked list is:-\n");
  while (head != NULL)
  {
    printf("\n%p is the address of %d value\n", head->next, head->val); // first in first out
    head = head->next;
  }
}

link *deletenode(link *newnode, link *head)
{
  int deleteVal;
  printf("\nenter the value of the node you want to delete:-\n");
  scanf("%d", &deleteVal);
  link *before, *nodeDel, *after;
  nodeDel = head;
  if (head->val != deleteVal)
  {
    while (nodeDel->val != deleteVal)
    {
      before = nodeDel;
      after = nodeDel->next;
      nodeDel = nodeDel->next;
    }
    before->next = after->next;
  }
  else
  {
    head = head->next;
  }
  return head;
}

void countNode(link **head)
{
  link *temp = *head;
  int count = 0;
  while (temp != NULL)
  {
    count++;
    temp = temp->next;
  }
  printf("\nnodes are %d", count);
}
void findNode(link **head)
{
  int value, flag;
  printf("\ninput the value to find in the linked list\n");
  scanf("%d", &value);
  link *temp = *head;
  while (temp != NULL)
  {
    if (temp->val == value)
    {
      printf("\n----------number is present----------\n");
      flag = 1;
      break;
    }
    temp = temp->next;
  }
  if (flag != 1)
  {
    printf("\n----------number is not present----------\n");
  }
}
int main()
{
  int choice;
  link *newnode = NULL, *head = NULL, *temp = NULL;

  do
  {
    printf("\n\ninput the choice\n1-make a linked list\n2-display\n3-delete\n4-count node\n5-find node");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      head = makeLink(newnode, head, temp);
      break;
    case 2:
      display(head);
      break;
    case 3:
      head = deletenode(newnode, head);
      break;
    case 4:
      countNode(&head);
      break;
    case 5:
      findNode(&head);
      break;
    }
  } while (choice <= 6);
}
