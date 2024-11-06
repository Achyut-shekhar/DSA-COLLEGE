#include <stdio.h>
#include <stdlib.h>

typedef struct dl
{
  int data;
  struct dl *next;
  struct dl *prev;
} dl;

dl *createlink(dl *head)
{
  int ch;
  dl *newnode = NULL, *temp = NULL;
  while (1)
  {
    newnode = (dl *)malloc(sizeof(dl));
    printf("\ninput the data");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL)
    {
      head = temp = newnode;
      temp->prev = NULL;
    }
    else
    {
      temp->next = newnode;
      newnode->prev = temp;
      temp = newnode;
    }
    printf("\nend-0");
    scanf("%d", &ch);
    if (ch == 0)
      break;
  }
  return head;
}
void display(dl *head)
{
  while (head != NULL)
  {
    printf("\n%d %p %p", head->data, head->prev, head->next);
    head = head->next;
  }
}
dl *deletek(dl *head)
{
  int k;
  dl *temp = head;
  printf("\ninput the k value");
  scanf("%d", &k);
  while (temp != NULL)
  {
    if (temp->data < k)
    {
      if (temp == head)
      {
        head = head->next;
        head->prev = NULL;
        free(temp);
        temp = head;
      }
      else
      {
        if (temp->next = NULL)
        {
          temp->prev->next = NULL;
        }
        else
          temp->prev->next = temp->next;
        dl *deletet = temp;
        temp = temp->next;
        free(deletet);
      }
    }

    else
    {
      temp = temp->next;
    }
  }
  return head;
}

int main()
{
  dl *head = NULL;
  head = createlink(head);
  display(head);
  head = deletek(head);
  display(head);
}
