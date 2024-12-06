#include <stdio.h>
#include <stdlib.h>
typedef struct link
{
  int val;
  struct link *next;
} link;

void printReverse(link *head)
{
  if (head == NULL)
  {
    return;
  }
  // using recursion
  printReverse(head->next);
  printf("\n%d", head->val);
}

int main()
{
  link *newnode = NULL, *temp = NULL; // in this we only need newnode which will save the value every new malloc and temp is storing the value for next
                                      // node
  int ch, v;
  while (1)
  {
    newnode = (link *)malloc(sizeof(link));
    if (newnode != NULL)
    {
      printf("input the value of data\n");
      scanf("%d", &v);
      newnode->val = v;
      newnode->next = temp;
      temp = newnode; // here we are storing the address of the newnode in temp so we can store the address of the previous node in the  next
    }
    printf("do you want to continue\n");
    scanf("%d", &ch);
    if (ch == 0)
      break;
  }
  printReverse(newnode);
  printf("\n\n");
  newnode = temp;
  while (newnode != NULL)
  {
    printf("%d\t%p\n", newnode->val, newnode->next);
    newnode = newnode->next;
  }
}
