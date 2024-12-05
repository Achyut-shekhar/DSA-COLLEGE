#include <stdio.h>
#include <stdlib.h>
#define maxNode 4
typedef struct node
{
  int vertexNum;
  struct node *next;
} node;

typedef struct list
{
  node *head;
} list;

list *adjilist[maxNode] = {0};

void add(int s, int d)
{
  node *dest, *tmp, *src;

  if (adjilist[s]->head == NULL)
  {
    src = (node *)malloc(sizeof(node));
    src->vertexNum = s;
    src->next = NULL;
    adjilist[s]->head = src;
  }

  dest = (node *)malloc(sizeof(node));
  dest->vertexNum = d;
  dest->next = NULL;
  tmp = adjilist[s]->head;
  while (tmp->next != NULL)
  {
    tmp = tmp->next;
  }
  tmp->next = dest;
}

void printlist()
{
  int i;
  for (i = 0; i < maxNode; ++i)
  {
    node *p = adjilist[i]->head;
    printf("adjacency list of the vertex %d\n", i);

    while (p)
    {
      printf("%d->", p->vertexNum);
      p = p->next;
    }
    printf("\n");
  }
}
int main()
{
  int i;
  for (i = 0; i < maxNode; i++)
  {
    adjilist[i] = (list *)malloc(sizeof(list));
    adjilist[i]->head = NULL;
  }

  add(0, 1);
  add(0, 2);
  add(1, 3);
  add(2, 4);
  printlist();
  return 0;
}