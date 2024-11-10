#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
} node;

node *createlink(node *head)
{
  node *newnode = NULL, *temp = NULL;
  int ch;
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
    printf("\nend-0");
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
    printf("\n");
    printf("%d ", head->data);
    head = head->next;
  }
}
node *separate(node *head)
{
  int val;
  node *newhead = NULL;
  printf("\ninput the value in link\n");
  scanf("%d", &val);
  while (head->data != val && head != NULL)
  {
    head = head->next;
  }
  if (head->next == NULL)
  {
    printf("\nnot in the list\n");
  }
  else
  {
    newhead = head->next;
    head->next = NULL;
  }
  return newhead;
}
node *reverse(node *head)
{
  node *curr = head;
  node *after = NULL, *prev = NULL;
  while (curr != NULL)
  {
    after = curr->next;
    curr->next = prev;

    prev = curr;
    curr = after;
  }
  return prev;
}

void pallindrome(node *head)
{
  int res = 0;
  node *slow = head, *fast = head;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  node *secondHalf = reverse(slow);
  node *firstHalf = head;

  node *tempSecond = secondHalf;
  while (tempSecond != NULL)
  {
    if (firstHalf->data != tempSecond->data)
    {
      res = 1;
    }
    firstHalf = firstHalf->next;
    tempSecond = tempSecond->next;
  }
  if (res == 0)
    printf("\npallindrome");
  else
    printf("\nnot pallindrome");

  reverse(secondHalf);
}
int main()
{
  node *head = NULL;
  node *newhead = NULL;
  int ch;
  do
  {
    printf("\ninput choices");
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
      newhead = separate(head);
      display(newhead);
      display(head);
      break;
    case 4:
      head = reverse(head);
      display(head);
      break;
    case 5:
      pallindrome(head);
      break;
    }

  } while (ch != 0);
}