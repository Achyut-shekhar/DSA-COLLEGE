#include <stdio.h>
#include <stdlib.h>

// Stack structure
struct Stack
{
  int data;
  struct Stack *next;
};

// Function to create a new stack node
struct Stack *newNode(int data)
{
  struct Stack *stackNode = (struct Stack *)malloc(sizeof(struct Stack));
  stackNode->data = data;
  stackNode->next = NULL;
  return stackNode;
}

// Function to push an element onto the stack
void push(struct Stack **top_ref, int data)
{
  struct Stack *stackNode = newNode(data);
  stackNode->next = *top_ref;
  *top_ref = stackNode;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *top)
{
  return !top;
}

// Function to pop an element from the stack
int pop(struct Stack **top_ref)
{
  if (isEmpty(*top_ref))
  {
    printf("Stack is empty\n");
    return -1;
  }
  struct Stack *temp = *top_ref;
  *top_ref = (*top_ref)->next;
  int popped = temp->data;
  free(temp);
  return popped;
}

// Recursive function to print the stack in queue order
void printQueueOrder(struct Stack **top_ref)
{
  if (*top_ref == NULL)
  {
    return;
  }

  // Pop the top element
  int topElement = pop(top_ref);

  // Recursive call for the rest of the stack
  printQueueOrder(top_ref);

  // Print the popped element (in reverse order)
  printf("%d ", topElement);

  // Push the element back to restore the stack (optional if needed)
  push(top_ref, topElement);
}

// Main function
int main()
{
  struct Stack *stack = NULL;

  // Push elements onto the stack
  push(&stack, 1);
  push(&stack, 2);
  push(&stack, 3);
  push(&stack, 4);
  push(&stack, 5);

  printf("Elements in queue order: ");
  printQueueOrder(&stack);
  printf("\n");

  return 0;
}
