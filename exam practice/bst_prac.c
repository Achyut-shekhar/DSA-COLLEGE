#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *left, *right;
} node;
node *create(int val)
{
  node *newnode = (node *)malloc(sizeof(node));
  newnode->data = val;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

node *insert(node *root, int val)
{
  if (root == NULL)
    root = create(val);
  if (val < root->data)
    root->left = insert(root->left, val);
  else if (val > root->data)
    root->right = insert(root->right, val);
  return root;
}

void print(node *root)
{
  if (root != NULL)
  {
    print(root->left);
    printf("%d->", root->data);
    print(root->right);
  }
}

node *getSuccessor(node *root)
{
  while (root != NULL && root->left != NULL)
  {
    root = root->left;
  }
  return root;
}
node *delete(node *root, int val)
{
  if (root == NULL)
    return root;
  if (val < root->data)
    root->left = delete (root->left, val);
  else if (val > root->data)
    root->right = delete (root->right, val);
  else
  {
    if (root->left == NULL && root->right == NULL)
    {
      free(root);
      return NULL;
    }

    if (root->left == NULL)
    {
      node *temp = root->right;
      free(root);
      return temp;
    }
    if (root->right == NULL)
    {
      node *temp = root->left;
      free(root);
      return temp;
    }

    node *succ = getSuccessor(root->right);
    root->data = succ->data;
    root->right = delete (root->right, succ->data);
  }
}

int main()
{
  node *root = NULL;

  root = insert(root, 30);
  root = insert(root, 10);
  root = insert(root, 8);
  root = insert(root, 11);
  root = insert(root, 40);
  root = insert(root, 35);

  print(root);

  root = delete (root, 11);
  printf("\n-----------deleted-------\n");
  print(root);
}
