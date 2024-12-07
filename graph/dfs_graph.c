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
  node *dest, *tmp;

  dest = (node *)malloc(sizeof(node));
  dest->vertexNum = d;
  dest->next = NULL;

  if (adjilist[s]->head == NULL)
  {
    adjilist[s]->head = dest; // Directly set the head to the first destination node
  }
  else
  {
    tmp = adjilist[s]->head;
    while (tmp->next != NULL)
    {
      tmp = tmp->next;
    }
    tmp->next = dest; // Append the destination node at the end
  }
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

void dfsutil(int vertex, int visited[])
{
  visited[vertex] = 1;
  printf("%d ", vertex);

  node *temp = adjilist[vertex]->head; // Start from the head of the list

  while (temp != NULL)
  {
    if (!visited[temp->vertexNum])
    {
      dfsutil(temp->vertexNum, visited);
    }
    temp = temp->next;
  }
}
void dfs(int startVertex)
{
  int visited[maxNode] = {0}; // initialize visited vertex
  printf("DFS starting from vertex %d:\n", startVertex);
  dfsutil(startVertex, visited);
  printf("\n");
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

  int startVertex;
  printf("enter the starting vertex for DFS");
  scanf("%d", &startVertex);
  dfs(startVertex);

  return 0;
}