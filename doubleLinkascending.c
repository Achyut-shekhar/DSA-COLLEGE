// create a double linked list in such a way that the resultant linked list remain in ascending order.
#include <stdio.h>
typedef struct doubleLink
{
  struct doubleLink *prev;
  int data;
  struct doubleLink *next;
} dl;
dl *insertnode(dl *head, int val)
{
  dl *newnode = (dl *)malloc(sizeof(dl *));
  newnode->prev = NULL;
  newnode->next = NULL;
  newnode->data = val;
  return newnode;
}
dl *createlink(dl *head, int val)
{
  head = NULL;
  dl *newnode = insertnode(head, val);
  if (head == NULL)
  {
    return newnode;
  }
  dl *curr = head;
  // checking whether the newnode will not insert before head
  if (val <= head->data)
  {
    newnode->next = head;
    head->prev = newnode;
    return newnode;
  }
  // treaversing and finding the right position
  while (curr->next->data < val)
  {
    curr = curr->next;
  }

  newnode->next = curr->next;
  if (curr->next != NULL)
  {
    curr->next->prev = newnode;
  }
  curr->next = newnode;
  newnode->prev = curr;

  return head;
}
void displayList(dl *head)
{
  printf("\nList in ascending order:\n");
  while (head != NULL)
  {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}
int main()
{
  int val;
  printf("\ninput the data of the node\n");
  scanf("%d", &val);

  dl *head = createlink(head, val);
  displayList(head);
}