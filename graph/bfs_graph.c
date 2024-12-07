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
    printf("Adjacency list of the vertex %d\n", i);

    while (p)
    {
      printf("%d -> ", p->vertexNum);
      p = p->next;
    }
    printf("NULL\n");
  }
}

void bfs(int startVertex)
{
  int visited[maxNode] = {0};
  int queue[maxNode];
  int front = 0, rear = 0;

  // Mark the visited vertex
  visited[startVertex] = 1;
  queue[rear++] = startVertex;

  printf("BFS starting from vertex %d:\n", startVertex);

  while (front < rear)
  {
    // Dequeue a vertex
    int currentVertex = queue[front++];
    printf("%d ", currentVertex);

    // Traverse all adjacent vertices
    node *temp = adjilist[currentVertex]->head;
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

  // Initialize adjacency list
  for (i = 0; i < maxNode; i++)
  {
    adjilist[i] = (list *)malloc(sizeof(list));
    adjilist[i]->head = NULL;
  }

  printf("Enter the number of edges: ");
  scanf("%d", &edges);

  printf("Enter the edges (source and destination) separated by space:\n");
  for (i = 0; i < edges; i++)
  {
    printf("Edge %d: ", i + 1);
    scanf("%d%d", &s, &d);
    add(s, d);
  }

  // Print adjacency list
  printlist();

  // Perform BFS
  int startVertexBFS;
  printf("Enter the starting vertex for BFS: ");
  scanf("%d", &startVertexBFS);
  bfs(startVertexBFS);

  return 0;
}
