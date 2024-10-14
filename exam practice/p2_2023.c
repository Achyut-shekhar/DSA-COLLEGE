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
link *add(link *head)
{
  int val;
  link *p, *temp;
  temp = head;
  printf("\ninput the data want to find");
  scanf("%d", &val);
  printf("\ninput the data");
  p = (link *)malloc(sizeof(link));
  scanf("%d", &p->data);
  link *current = head;
  // Traverse the list to find the value
  do
  {
    if (current->next->data == val)
    {
      p->next = current->next; // New node points to the next node
      current->next = p;       // Current node points to new node
      return head;             // Return unchanged head
    }
    current = current->next; // Move to next node
  } while (current != head);

  printf("Value %d not found in the list.\n", val);
  free(p);     // Free the memory of the new node if not added
  return head; // Return unchanged head
}
int main()
{
  printf("make a linked list");
  link *head = NULL;
  head = makeLink(head);
  display(head);
  head = add(head);
  display(head);
}
