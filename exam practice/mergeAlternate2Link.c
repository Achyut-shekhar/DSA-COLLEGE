#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node
{
  int data;
  struct node *next;
} node;

// Function to create a new node
node *insert(int val)
{
  node *newnode = (node *)malloc(sizeof(node));
  newnode->data = val;
  newnode->next = NULL;
  return newnode;
}

// Function to create a linked list
node *create(node *head)
{
  int val, ch = 0;
  node *newnode = NULL, *temp = NULL;
  while (1)
  {
    printf("\nInput the data: ");
    scanf("%d", &val);
    newnode = insert(val);

    if (head == NULL)
    {
      head = temp = newnode;
    }
    else
    {
      temp->next = newnode;
      temp = newnode;
    }

    printf("If you want to end, press '0': ");
    scanf("%d", &ch);
    if (ch == 0)
      break;
  }
  return head;
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

// Function to merge two linked lists alternatively
node *merge(node *hd1, node *hd2)
{
  node *mergedHead = NULL, *mergedTail = NULL;

  // Alternate merging of nodes from both lists
  while (hd1 != NULL || hd2 != NULL)
  {
    if (hd1 != NULL)
    {
      node *newnode = insert(hd1->data);
      if (mergedHead == NULL)
      {
        mergedHead = mergedTail = newnode;
      }
      else
      {
        mergedTail->next = newnode;
        mergedTail = newnode;
      }
      hd1 = hd1->next;
    }

    if (hd2 != NULL)
    {
      node *newnode = insert(hd2->data);
      if (mergedHead == NULL)
      {
        mergedHead = mergedTail = newnode;
      }
      else
      {
        mergedTail->next = newnode;
        mergedTail = newnode;
      }
      hd2 = hd2->next;
    }
  }

  return mergedHead;
}

int main()
{
  node *head1 = NULL, *head2 = NULL, *mergedHead = NULL;

  printf("Create the 1st singly linked list:\n");
  head1 = create(head1);
  printf("First linked list: ");
  display(head1);

  printf("\nCreate the 2nd singly linked list:\n");
  head2 = create(head2);
  printf("Second linked list: ");
  display(head2);

  mergedHead = merge(head1, head2);
  printf("\nMerged linked list: ");
  display(mergedHead);

  return 0;
}
