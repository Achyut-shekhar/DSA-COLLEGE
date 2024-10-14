#include <stdio.h>
#include <stdlib.h>
typedef struct link
{
  int data;
  struct link *next;
} link;
link *makeLink(link *head)
{
  int ch;
  link *p = NULL, *temp = NULL;
  while (1)
  {
    p = (link *)malloc(sizeof(link));
    printf("input the data");
    scanf("%d", &p->data);
    if (head == NULL)
    {                    // First node
      head = p;          // Assign head
      head->next = head; // Point to itself
      temp = head;       // Set temp to the head
    }
    else
    {
      temp->next = p; // Link the last node to the new node
      p->next = head; // New node points to head
      temp = p;       // Move temp to the new node
    }
    printf("continue");
    scanf("%d", &ch);
    if (ch == 0)
    {
      temp->next = head;
      break;
    }
  }
  return head;
}
void display(link *head)
{
  link *temp;
  if (head == NULL)
  {
    printf("empty");
    return;
  }
  else
  {
    temp = head;
    do
    {
      printf("\n%d\t%d", temp->data, temp->next);
      temp = temp->next;
    } while (temp != head);
  }
}
link *split(link *head)
{
  int val;
  link *temp, *p;
  temp = head;
  printf("input the value from split");
  scanf("%d", &val);
  do
  {
    if (temp->next->data == val)
    {
      temp->next->next = NULL;
      break;
    }
    temp = temp->next;
  } while (temp != head);
  return head; // Return unchanged head
}
int main()
{
  printf("make a linked list");
  link *head = NULL;
  head = makeLink(head);
  display(head);
  head = split(head);
  display(head);
}
