#include <stdio.h>
#include <stdlib.h>
typedef struct doubl
{
  struct doubl *prev;
  int data;
  struct doubl *next;
} doubl;
doubl *insert(doubl *temp)
{
  doubl *newnode = NULL;
  printf("input the data");
  newnode = (doubl *)malloc(sizeof(doubl));
  newnode->next = NULL;
  if (newnode != NULL)
  {
    printf("input the data");
    scanf("%d", &newnode->data);
    if (temp == NULL)

    {
      temp = newnode;
      newnode->prev = NULL;
    }
    else
    {
      temp->next = newnode;
      newnode->prev = temp;
      temp = newnode;
    }
    temp->next = NULL;
  }
  return temp;
}
doubl *delete(doubl *head)
{
  if (head == NULL)
    printf("error");
  else
  {
    doubl *temp = head;
    printf("Deleted node data: %d\n", temp->data);

    head = head->next;
    if (head != NULL)
    {
      head->prev = NULL;
    }

    free(temp);
    return head;
  }
}

void display(doubl *head)
{
  printf("\ndisplay is:-");
  while (head != NULL)
  {
    printf("\n%p\t%p\t%d", head->prev, head->next, head->data);
    head = head->next;
  }
}

doubl *insertBetween(doubl *head)
{
  doubl *t = head, *newnode = NULL;
  int val;
  int pos;
  newnode = (doubl *)malloc(sizeof(doubl));
  printf("\ninput after=1\nbedore=0\n");
  scanf("%d", &pos);
  printf("\ninput the value you want to enter\n");
  scanf("%d", &newnode->data);
  printf("\ninput the data which in the linked list\n");
  scanf("%d", &val);
  if (pos == 1)
  { // insert after
    while (t->data != val)
    {
      t = t->next;
    }
    // if insert after the last node
    if (t->next == NULL)
    {
      newnode->prev = t;
      newnode->next = NULL;
      t->next = newnode;
    }
    else
    {
      t->next->prev = newnode;
      newnode->next = t->next;
      newnode->prev = t; // putting address of t in newnode prev
      t->next = newnode; // set the next of the t node
    }
  }
  else
  { // insert before
    // if insert before head
    if (head->data == val)
    {
      head->prev = newnode;
      newnode->next = head;
      newnode->prev = NULL;
      head = newnode;
    }
    else
    { // insert before other than head
      while (t->next->data != val)
      {
        t = t->next;
      }
      newnode->next = t->next;
      newnode->prev = t;
      t->next = newnode;
    }
  }
  return head;
}

void deletebetween(doubl *head)
{
  int delValue;
  printf("\ninput the value which you want to delete\n");
  scanf("%d", &delValue);
  doubl *temp = head;
  while (temp->data != delValue)
  {
    temp = temp->next;
  }
  if (temp->next == NULL)
  {
    temp->prev->next = NULL;
  }
  else
  {
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
  }
  free(temp);
}

main()
{
  doubl *head = NULL, *temp = NULL;
  int ch;
  do
  {
    printf("\n1-insert\n2-delete the first node\n3-display\n4-insert between before and after\n5-delete between first and last node ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      temp = insert(temp);
      if (head == NULL)
        head = temp;
      break;
    case 2:
      head = delete (head);
      if (head == NULL)
        temp = NULL;
      break;
    case 3:
      display(head);
      break;
    case 4:
      head = insertBetween(head);
      break;
    case 5:
      deletebetween(head);
      break;
    }
  } while (ch <= 5);
}
