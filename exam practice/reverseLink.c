#include <stdio.h>
#include <stdlib.h>
typedef struct link
{
  int data;
  struct link *next;
} link;
link *createlink(link *head)
{
  link *newnode = NULL, *temp = NULL;
  int ch;
  while (1)
  {
    newnode = (link *)malloc(sizeof(link));
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
    printf("if dont want to constinue press 0");
    scanf("%d", &ch);
    if (ch == 0)
      break;
  }
  return head;
}
void display(link *head)
{
  printf("\n");
  while (head != NULL)
  {
    printf("%d ", head->data);
    head = head->next;
  }
}
link *reverselink(link *head)
{
  link *curr = head, *after = NULL, *prev = NULL;
  while (curr != NULL)
  {
    after = curr->next;
    curr->next = prev;
    prev = curr;
    curr = after;
  }
  return prev;
}

// void findpalin(struct link* head){
//     struct link* temp = head;
//     int cnt = 1;

//     while(temp != NULL){
//         cnt++;
//         temp = temp->next;

//     }
//         temp = head;

//     if(cnt%2 == 0)
//     {
//       for(int i =0; i<cnt/2; i++){

//       }

//     }
//     else{

//     }
// }

link *deletealternate(link *head)
{
  link *temp = NULL;
  while (head != NULL && head->next != NULL)
  {
    temp = head->next;
    head->next = temp->next;
    free(temp);
    head = head->next;
  }
}

void separatelink(link *head)
{
  link *headeven = NULL, *headodd = NULL, *newnode = NULL, *tempev = NULL, *tempod = NULL;
  while (head != NULL)
  {
    if (head->data % 2 == 0)
    {
      newnode = (link *)malloc(sizeof(link));
      newnode->data = head->data;
      newnode->next = NULL;
      if (headeven == NULL)
      {
        headeven = tempev = newnode;
      }
      else
      {
        tempev->next = newnode;
        tempev = newnode;
      }
    }
    else
    {

      newnode = (link *)malloc(sizeof(link));
      newnode->data = head->data;
      newnode->next = NULL;
      if (headodd == NULL)
      {
        headodd = tempod = newnode;
      }
      else
      {
        tempod->next = newnode;
        tempod = newnode;
      }
    }
    head = head->next;
  }
  printf("\neven link list");
  display(headeven);
  printf("\nodd link list");
  display(headodd);
}
int main()
{
  link *head = NULL;
  printf("\ncreate the link");
  head = createlink(head);
  display(head);

  separatelink(head);

  deletealternate(head);
  display(head);

  head = reverselink(head);
  display(head);
}