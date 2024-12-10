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

void bfs(int vertex)
{
  int front = 0, rear = 0;
  int queue[maxnode];
  int visited[maxnode] = {0};

  visited[vertex] = 1;
  queue[rear++] = vertex;
  printf("starting vertex is %d\n", vertex);

  while (front < rear)
  {
    int currentVertex = queue[front++];
    printf("%d", currentVertex);

    node *temp = adjilist[currentVertex]->head;

    while (temp)
    {
      if (!visited[temp->data])
      {
        visited[temp->data] = 1;
        queue[rear++] = temp->data;
      }
      temp = temp->next;
    }
  }
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

  bfs(startVertex);

  print();
}
