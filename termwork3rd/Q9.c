#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void createGraph(int graph[MAX][MAX], int vertices);
void displayGraph(int graph[MAX][MAX], int vertices);

int main()
{
  int graph[MAX][MAX] = {0}, vertices, choice;
  printf("Enter number of vertices: ");
  scanf("%d", &vertices);

  while (1)
  {
    printf("\n1. Create Graph\n2. Display Graph\n3. Exit\nChoice: ");
    scanf("%d", &choice);
    if (choice == 1)
      createGraph(graph, vertices);
    else if (choice == 2)
      displayGraph(graph, vertices);
    else if (choice == 3)
      exit(0);
    else
      printf("Invalid choice.\n");
  }
  return 0;
}

void createGraph(int graph[MAX][MAX], int vertices)
{
  int edges, u, v, weight;
  printf("Enter number of edges: ");
  scanf("%d", &edges);
  for (int i = 0; i < edges; i++)
  {
    printf("Edge (u v weight): ");
    scanf("%d %d %d", &u, &v, &weight);
    if (u >= 0 && u < vertices && v >= 0 && v < vertices)
    {
      graph[u][v] = weight; // For directed graph
      graph[v][u] = weight; // Uncomment for undirected graph
    }
    else
    {
      printf("Invalid edge, try again.\n");
      i--;
    }
  }
}

void displayGraph(int graph[MAX][MAX], int vertices)
{
  printf("\nAdjacency Matrix:\n");
  for (int i = 0; i < vertices; i++)
  {
    for (int j = 0; j < vertices; j++)
      printf("%d ", graph[i][j]);
    printf("\n");
  }
}