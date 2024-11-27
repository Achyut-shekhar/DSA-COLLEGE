#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum number of vertices

int graph[MAX][MAX] = {0}; // Adjacency matrix
int visited[MAX] = {0};    // Visited array for DFS

// Function prototypes
void createGraph(int vertices, int edges);
void DFS(int vertex, int vertices);
void BFS(int startVertex, int vertices);

int main()
{
  int vertices, edges, startVertex, choice;

  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);

  printf("Enter the number of edges: ");
  scanf("%d", &edges);

  createGraph(vertices, edges);

  while (1)
  {
    printf("\n1. Depth-First Search (DFS)");
    printf("\n2. Breadth-First Search (BFS)");
    printf("\n3. Exit\nChoice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter the starting vertex for DFS: ");
      scanf("%d", &startVertex);
      for (int i = 0; i < vertices; i++)
        visited[i] = 0; // Reset visited array
      printf("DFS Traversal: ");
      DFS(startVertex, vertices);
      printf("\n");
      break;

    case 2:
      printf("Enter the starting vertex for BFS: ");
      scanf("%d", &startVertex);
      printf("BFS Traversal: ");
      BFS(startVertex, vertices);
      printf("\n");
      break;

    case 3:
      exit(0);

    default:
      printf("Invalid choice. Try again.\n");
    }
  }

  return 0;
}

// Function to create the graph
void createGraph(int vertices, int edges)
{
  int u, v;

  printf("Enter the edges (u v) for the graph:\n");
  for (int i = 0; i < edges; i++)
  {
    scanf("%d %d", &u, &v);
    if (u >= 0 && u < vertices && v >= 0 && v < vertices)
    {
      graph[u][v] = 1; // Add edge for directed graph
      graph[v][u] = 1; // Uncomment for undirected graph
    }
    else
    {
      printf("Invalid edge. Try again.\n");
      i--;
    }
  }
}

// Depth-First Search (DFS)
void DFS(int vertex, int vertices)
{
  printf("%d ", vertex);
  visited[vertex] = 1;

  for (int i = 0; i < vertices; i++)
  {
    if (graph[vertex][i] == 1 && !visited[i])
    {
      DFS(i, vertices);
    }
  }
}

// Breadth-First Search (BFS)
void BFS(int startVertex, int vertices)
{
  int queue[MAX], front = 0, rear = 0;
  int visited[MAX] = {0};

  // Enqueue the start vertex
  queue[rear++] = startVertex;
  visited[startVertex] = 1;

  while (front < rear)
  {
    int currentVertex = queue[front++];
    printf("%d ", currentVertex);

    // Visit all adjacent vertices
    for (int i = 0; i < vertices; i++)
    {
      if (graph[currentVertex][i] == 1 && !visited[i])
      {
        queue[rear++] = i;
        visited[i] = 1;
      }
    }
  }
}
