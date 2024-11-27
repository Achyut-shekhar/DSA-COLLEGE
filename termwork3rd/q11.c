// Q11 Write a C program implement Kurskals algorithm to find minimal spanning tree from a given graph.

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// Structure to represent an edge
typedef struct Edge
{
  int u, v, weight;
  struct Edge *next;
} Edge;

// Union-Find data structure to detect cycles
int parent[MAX];

// Function prototypes
void initUnionFind(int vertices);
int find(int i);
void unionSet(int i, int j);
void addEdge(Edge **head, int u, int v, int weight);
void displayEdges(Edge *head);
void kruskal(int vertices, Edge *head);

int main()
{
  Edge *edges = NULL; // Initialize the linked list of edges
  int vertices, choice, u, v, weight;

  // Input for the number of vertices
  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);

  // Main menu-driven loop
  while (1)
  {
    printf("\nMenu:\n");
    printf("1. Add Edge\n");
    printf("2. Display Edges\n");
    printf("3. Kruskal's Algorithm (MST)\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      // Input for adding an edge
      printf("Enter edge (u v weight): ");
      scanf("%d %d %d", &u, &v, &weight);
      addEdge(&edges, u, v, weight); // Pass the address of the head pointer
      break;
    case 2:
      // Display the edges
      displayEdges(edges);
      break;
    case 3:
      // Kruskal's Algorithm
      initUnionFind(vertices);  // Initialize Union-Find
      kruskal(vertices, edges); // Apply Kruskal's algorithm
      break;
    case 4:
      // Exit the program
      printf("Exiting...\n");
      exit(0);
    default:
      printf("Invalid choice. Try again.\n");
    }
  }

  return 0;
}

// Function to initialize the Union-Find data structure
void initUnionFind(int vertices)
{
  for (int i = 0; i < vertices; i++)
  {
    parent[i] = i; // Initially, each node is its own parent
  }
}

// Function to find the root of the set to which element i belongs
int find(int i)
{
  if (i != parent[i])
  {
    parent[i] = find(parent[i]); // Path compression
  }
  return parent[i];
}

// Function to perform union of two sets (i and j)
void unionSet(int i, int j)
{
  int rootI = find(i);
  int rootJ = find(j);

  if (rootI != rootJ)
  {
    parent[rootI] = rootJ; // Union by assigning the root of j to root of i
  }
}

// Function to add an edge to the linked list of edges
void addEdge(Edge **head, int u, int v, int weight)
{
  Edge *newEdge = (Edge *)malloc(sizeof(Edge));
  newEdge->u = u;
  newEdge->v = v;
  newEdge->weight = weight;
  newEdge->next = NULL;

  // Add edge to the linked list
  if (*head == NULL)
  {
    *head = newEdge;
  }
  else
  {
    Edge *temp = *head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newEdge;
  }
}

// Function to display the edges in the graph
void displayEdges(Edge *head)
{
  printf("\nEdges in the graph:\n");
  while (head != NULL)
  {
    printf("%d -- %d (Weight: %d)\n", head->u, head->v, head->weight);
    head = head->next;
  }
}

// Kruskal’s Algorithm to find MST
void kruskal(int vertices, Edge *head)
{
  int mstWeight = 0;
  int mstEdges = 0;
  Edge *edge = head;
  printf("\nEdges in the MST:\n");

  while (edge != NULL && mstEdges < vertices - 1)
  {
    int u = edge->u;
    int v = edge->v;

    // Check if adding this edge will form a cycle
    if (find(u) != find(v))
    {
      // Include this edge in the MST
      printf("%d -- %d (Weight: %d)\n", u, v, edge->weight);
      mstWeight += edge->weight;
      mstEdges++;
      unionSet(u, v); // Merge the two sets
    }
    edge = edge->next;
  }

  printf("\nTotal weight of MST: %d\n", mstWeight);
}