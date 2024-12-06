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
  int i, edges, s, d;
  for (i = 0; i < maxNode; i++)
  {
    adjilist[i] = (list *)malloc(sizeof(list));
    adjilist[i]->head = NULL;
  }

  printf("enter the number of edges: ");
  scanf("%d", &edges);

  printf("enter the edges (source and destination) separated by space:\n");
  for (i = 0; i < edges; i++)
  {
    printf("edges %d: ", i + 1);
    scanf("%d%d", &s, &d);
    add(s, d);
  }

  printlist();
  return 0;
}