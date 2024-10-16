#include <stdio.h>
#include <stdlib.h>
typedef struct PQlink
{
  int val;
  int priority;
  struct PQlink *next;
} pq;

pq *enque(pq *head)
{
  pq *newnode = NULL, *temp = NULL;

  int ch = 1;
  while (ch)
  {
    newnode = (pq *)malloc(sizeof(pq));
    printf("input the priority and the value");
    scanf("%d %d", &newnode->priority, &newnode->val);
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
void display(pq *head)
{
  while (head != NULL)
  {
    printf("\npriority is %d value is %d\n", head->priority, head->val);
    head = head->next;
  }
}

pq *deque(pq *head)
{
  if (head == NULL)
  {
    printf("Queue is empty\n");
    return head;
  }

  pq *temp = head, *prev = NULL, *minNode = head, *minPrev = NULL;

  // Find the node with the minimum priority
  while (temp != NULL)
  {
    if (temp->priority < minNode->priority)
    {
      minNode = temp;
      minPrev = prev;
    }
    prev = temp;
    temp = temp->next;
  }

  // Remove the minNode from the list
  if (minNode == head) // If minNode is the head
  {
    head = head->next;
  }
  else
  {
    minPrev->next = minNode->next;
  }

  printf("Dequeued: priority = %d, value = %d\n", minNode->priority, minNode->val);
  free(minNode);

  return head;
}

int main()
{

  int ch;
  pq *newnode = NULL, *head = NULL;
  do
  {
    printf("\n1-enque\n2-display\n3-deque");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      head = enque(head);
      break;
    case 2:
      display(head);
      break;
    case 3:
      head = deque(head);
      break;
    }
  } while (ch <= 5);
}