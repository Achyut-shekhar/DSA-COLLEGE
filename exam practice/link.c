#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
  int data;
  struct link *next;
} link;

link *make(link *head)
{
  int ch;
  link *newnode = NULL, *temp = NULL;
  while (1)
  {

    newnode = (link *)malloc(sizeof(link));
    printf("input the data");
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
    printf("0-end");
    scanf("%d", &ch);
    if (ch == 0)
      break;
  }
  return head;
}

void display(link *head)
{
  while (head != NULL)
  {
    printf("%d ", head->data);
    head = head->next;
  }
}

link *delete(link *head)
{
  link *temp = head;
  while (temp != NULL && temp->next != NULL)
  {
    if (temp == head && temp->data % 2 == 0)
    {
      head = head->next;
    }
    if (temp->next->data % 2 == 0)
    {
      temp->next = temp->next->next;
    }
    else
      temp = temp->next;
  }
  return head;
}

int main()
{
  link *head = NULL;
  int ch;
  do
  {
    printf("input the choice");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      head = make(head);
      break;
    case 2:
      display(head);
      break;
    case 3:
      head = delete (head);
      break;
    }
  } while (ch != 0);
}