// create a double linked list in such a way that the resultant linked list remain in ascending order.
#include <stdio.h>
#include <stdlib.h>
typedef struct doubleLink
{
  struct doubleLink *prev;
  int data;
  struct doubleLink *next;
} dl;
dl *insertnode(dl *head, int val)
{
  dl *newnode = (dl *)malloc(sizeof(dl));
  newnode->prev = NULL;
  newnode->next = NULL;
  newnode->data = val;
  return newnode;
}
dl *createlink(dl *head)
{
  int val;
  printf("\ninput the data of the node\n");
  scanf("%d", &val);
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
  while (curr->next != NULL && curr->next->data < val)//in this last valla check kr raha hai ki jis node peh curr   hai usske next node peh jo data hai voh chota hai ki nahi.
  {
    curr = curr->next;
  }

  newnode->next = curr->next;
  if (curr->next != NULL) //checking whether jiss node ke baad lagana hai voh last to nahi 
  {
    curr->next->prev = newnode;
  }
  curr->next = newnode; //agaar last hai toh sirf yeh step chalengeh
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
  dl *head = NULL;
  int choice;
  do
  {
    printf("\n1-create the node\n2-display\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      head = createlink(head);
      break;
    case 2:
      displayList(head);
      break;
    }
  } while (choice <= 2);
}