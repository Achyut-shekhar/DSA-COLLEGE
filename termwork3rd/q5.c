#include <stdio.h>
typedef struct node
{
  int data;
  struct node *next;
  struct node *prev;
} node;
node *createdoubly(node *head)
{
  node *newnode = NULL, *temp = NULL;
  int ch = 0;
  while (1)
  {
    newnode = (node *)malloc(sizeof(node));
    printf("\ninput the data of the node");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL)
    {
      head = temp = newnode;
    }
    else
    {
      newnode->prev = temp;
      temp->next = newnode;
      temp = newnode;
    }
    printf("\nto end press 0");
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
    printf("\n%d %x %x", head->data, head->next, head->prev);
    head = head->next;
  }
}

int intersection(node *head1, node *head2)
{
  node *temp = head2;
  while (head1 != NULL)
  {
    head2 = temp;
    while (head2 != NULL)
    {

      if (head1->data == head2->data)
      {
        return head2->data;
        break;
      }
      head2 = head2->next;
    }
    head1 = head1->next;
  }
  return 0;
}
int main()
{
  node *head1 = NULL;
  node *head2 = NULL;
  printf("\ncreate doubly linked list 1 is");
  head1 = createdoubly(head1);
  printf("\ncreate doubly linked list 2 is");
  head2 = createdoubly(head2);
  printf("\ndoubly linked list 1 is");
  display(head1);
  printf("\ndoubly linked list 2 is");
  display(head2);
  int num = intersection(head1, head2);
  printf("\n\n\tintersection node is %d", num);
}
