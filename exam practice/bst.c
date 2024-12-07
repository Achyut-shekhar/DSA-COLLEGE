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

node *insert(node *root, int data)
{
  if (root == NULL)
  {
    root = create(data);
  }
  if (data < root->data)
  {
    root->left = insert((root->left), data);
  }
  if (data > root->data)
  {
    root->right = insert((root->right), data);
  }
  return root;
}

void inOrder(node *root)
{
  if (root != NULL)
  {
    inOrder(root->left);
    printf("%d->\t", root->data);
    inOrder(root->right);
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

node *delete(node *root, int data)
{
  if (root == NULL)
    return root;

  // Navigate to the node to delete
  if (root->data > data)
    root->left = delete (root->left, data);
  else if (root->data < data)
    root->right = delete (root->right, data);
  else
  {
    // Case 1: Node with no children (leaf node)
    if (root->left == NULL && root->right == NULL)
    {
      free(root);
      return NULL;
    }

    // Case 2: Node with one child (either left or right)
    if (root->left == NULL) // Node with only right child
    {
      node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL) // Node with only left child
    {
      node *temp = root->left;
      free(root);
      return temp;
    }

    // Case 3: Node with two children
    node *succ = getSuccessor(root->right);         // Get the inorder successor
    root->data = succ->data;                        // Replace root data with successor's data
    root->right = delete (root->right, succ->data); // Delete the successor node
  }
  return root;
}

void countRightNode(node *root, int *count)
{
  if (root == NULL)
  {
    return;
  }

  (*count)++; // Increment count for the current node
  countRightNode(root->left, count);
  countRightNode(root->right, count);
}

int secondHighest(node *root)
{
  node *parent = NULL;
  node *current = root;
  while (current->right != NULL)
  {
    parent = current;
    current = current->right;
  }
  if (current && current->left != NULL)
    return getSuccessor(root->left);

  if (parent)
    return parent->data;
}

int Hight(node *root)
{
  if (root == NULL)
  {
    return -1;
  }

  return 1 + (Hight(root->left) > Hight(root->right) ? Hight(root->left) : Hight(root->right));
}

int countParent(node *root)
{
  if (root == NULL)
    return 0;

  int cnt = 0;
  if (root->left != NULL && root->right != NULL)
    cnt++;

  return cnt + countParent(root->right) + countParent(root->left);
}

int countleafNode(node *root)
{
  if (root == NULL)
    return 0;

  int countleaf = 0;
  if (root->left == NULL && root->right == NULL)
    countleaf++;

  return countleaf + countleafNode(root->right) + countleafNode(root->left);
}

int main()
{
  struct node *root = NULL;

  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 70);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 60);
  root = insert(root, 80);

  printf("---------inorder-------\n");
  inOrder(root);

  root = delete (root, 40);

  printf("\n------deleted bst--------\n");
  inOrder(root);

  printf("\n--------count right side node---------\n");
  int count;
  countRightNode(root->right, &count);
  printf("%d", count);

  printf("\n--------count all node---------\n");
  int allcount = 0;
  countRightNode(root, &allcount);
  printf("%d", allcount);

  printf("\n--------seconf highest------\n");
  int high = secondHighest(root);
  printf("%d", high);

  printf("\n--------height------\n");
  int hightNum = Hight(root);
  printf("%d", hightNum);

  printf("\n--------parent node------\n");
  int countNum = countParent(root);
  printf("%d", countNum);

  printf("\n--------left hand side node------\n");
  int countleft = 0;
  countRightNode(root->left, &countleft);
  printf("%d", countleft);

  printf("\n--------count leaf node------\n");

  int countleaf = countleafNode(root);
  printf("%d", countleaf);
  return 0;
}
