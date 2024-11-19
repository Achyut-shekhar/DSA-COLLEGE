// using double pointer

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *left, *right;
} node;

node *create(int data)
{
  node *newnode = (node *)malloc(sizeof(node));
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

void insert(node **root, int data)
{

  if (*root == NULL)
  {
    *root = create(data);
    return;
  }
  if (data < (*root)->data)
  {
    insert(&((*root)->left), data);
  }
  else if (data > (*root)->data)
  {
    insert(&((*root)->right), data);
  }
}

void inorder(node *root)
{
  if (root != NULL)
  {
    inorder(root->left);
    printf("%d  ", root->data);
    inorder(root->right);
  }
}

node *getSuccesor(node *curr)
{
  curr = curr->right;
  while (curr != NULL && curr->left != NULL)
    curr = curr->left;
  return curr;
}

void delete(node **root, int val)
{
  if ((*root) == NULL)
    return;

  if ((*root)->data > val)
    delete (&((*root)->left), val);
  else if ((*root)->data < val)
    delete (&((*root)->right), val);
  // 0 children
  else
  {
    if ((*root)->left == NULL)
    {
      node *temp = (*root)->right;
      free(*root);
      (*root) = temp;
      return;
    }
    // 1 left child
    if ((*root)->right == NULL)
    {
      node *temp = (*root)->left;
      free(*root);
      (*root) = temp;
      return;
    }
    // both children present
    node *succ = getSuccesor(*root);
    (*root)->data = succ->data;
    delete (&((*root)->right), succ->data);
  }
}

int countRightNode(node *root)
{

  if (root == NULL)
    return 0;

  return 1 + countRightNode(root->left) + countRightNode(root->right);
}
int main()
{
  struct node *root = NULL;
  int ch, data, delValue, count = 0;
  do
  {
    printf("\n input the choice");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("\ninput the data");
      scanf("%d", &data);
      insert(&root, data);
      break;
    case 2:
      inorder(root);
      break;
    case 3:
      printf("\ninput the data");
      scanf("%d", &delValue);
      delete (&root, delValue);
      break;
    case 4:
      count = countRightNode(root->right);
      printf("\n total number of rught hand side of root node");
      printf("\n%d", count);
      break;
    }

  } while (ch != 0);

  printf("\n\n------IN order-------\n");
  inorder(root);

  return 0;
}
