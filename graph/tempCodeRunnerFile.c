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

void dfsutil(int vertex, int visited[])
{
  visited[vertex] = 1;
  printf("%d ", vertex);

  node *temp = adjilist[vertex]->head->next;

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

void bfs(int startVertex)
{
  int visited[maxNode] = {0};
  int queue[maxNode];
  int front = 0, rear = 0;

  // marking the visited vertex
  visited[startVertex] = 1;
  queue[rear++] = startVertex;

  printf("bfs starting from vertex %d:\n", startVertex);

  while (front < rear)
  {
    // dequeu a vertex
    int currentVertex = queue[front++];
    printf("%d", currentVertex);

    // raversal all adjacent vertex
    node *temp = adjilist[currentVertex]->head->next;
    while (temp)
    {
      if (!visited[temp->vertexNum])
      {
        visited[temp->vertexNum] = 1;
        queue[rear++] = temp->vertexNum;
      }
      temp = temp->next;
    }
  }
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

  int startvertexbfs;
  printf("enter the starting vertex for BFS: ");
  scanf("%d", &startvertexbfs);
  bfs(startvertexbfs);

  int startVertex;
  printf("enter the starting vertex for DFS");
  scanf("%d", &startVertex);
  dfs(startVertex);

  while (getchar() != '\n')
    ; // Clear residual input

  return 0;
}