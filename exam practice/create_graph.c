#include <stdio.h>
#include <stdlib.h>
#define maxnode 5
typedef struct node
{
  int data;
  struct node *next;
} node;
typedef struct list
{
  node *head;
} list;

list *adjilist[maxnode] = {0};

void add(int s, int d)
{
  node *dest = NULL;
  node *temp = NULL;

  dest = (node *)malloc(sizeof(node));
  dest->data = d;
  dest->next = NULL;

  if (adjilist[s]->head == NULL)
  {
    adjilist[s]->head = dest;
  }
  else
  {
    temp = adjilist[s]->head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = dest;
  }
}

void print()
{
  int i;
  for (i = 0; i < maxnode; i++)
  {
    node *p = adjilist[i]->head;
    printf("\nfor the edge %d:\n", i);

    while (p)
    {
      printf("%d->", p->data);
      p = p->next;
    }
    printf("NULL");
  }
}
void dfsutil(int vertex, int visited[])
{
  visited[vertex] = 1;
  printf("%d ", vertex);

  node *temp = adjilist[vertex]->head;
  while (temp != NULL)
  {
    if (!visited[temp->data])
    {
      dfsutil(temp->data, visited);
    }
    temp = temp->next;
  }
}

void dfs(int vertex)
{
  int visited[maxnode] = {0};
  printf("dfs starting from the vertex %d: \n", vertex);
  dfsutil(vertex, visited);
  printf("\n");
}

int main()
{
  int i, edges, s, d;

  for (i = 0; i < maxnode; i++)
  {
    adjilist[i] = (list *)malloc(sizeof(list));
    adjilist[i]->head = NULL;
  }

  printf("\nenter the number of edges");
  scanf("%d", &edges);

  for (i = 0; i < edges; i++)
  {
    printf("\ninput the s and d");
    scanf("%d%d", &s, &d);
    add(s, d);
  }

  int startVertex;
  printf("input the start vertex");
  scanf("%d", &startVertex);
  
  print();
  printf("\n");

  dfs(startVertex);
}
