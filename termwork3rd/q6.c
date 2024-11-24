#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *left, *right;
} node;

node *insert(int val)
{
  node *newnode = NULL;
  newnode = (node *)malloc(sizeof(node));
  newnode->left = NULL;
  newnode->right = NULL;
  newnode->data = val;

  return newnode;
}

node *create(node *root, int val)
{

  if (root == NULL)
  {
    return insert(val);
  }
  if (root->data > val)
  {
    root->left = create((root->left), val);
  }
  else if (root->data < val)
  {
    root->right = create((root->right), val);
  }
  return root;
}
void display(node *root)
{
  if (root != NULL)
  {
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
  }
  printf("\n");
}
node *minValueNode(node *Node)
{
  node *current = Node;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}
int secondhighest(node *root)
{
  node *parent = NULL;
  node *current = root;

  while (current && current->right != NULL)
  {
    parent = current;
    current = current->right;
  }

  if (current && current->left != NULL)
  {
    return minValueNode((current->left)->data);
  }
  if (parent)
    return parent->data;
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

int countParent(node *root)
{
  if (root == NULL)
    return 0;

  int count = 0;
  if (root->left && root->right)
    count++;

  return count + countParent(root->left) + countParent(root->right);
}

int height(struct node *root)
{
  if (root == NULL)
    return -1; // Height of empty tree is -1
  return 1 + ((height(root->left) > height(root->right)) ? height(root->left) : height(root->right));
}

int leftNode(node *root)
{
  if (root == NULL || root->left == NULL)
    return 0;
  int count = 0;

  node *current = root->left;

  while (current != NULL)
  {
    count++;
    count += leftNode(current);
    current = current->right;
  }
  return count;
}
int main()
{
  node *root = NULL;
  int ch, val;
  int num, common, heightNum, leftNum;
  do
  {
    printf("\n1-create a binary search tree\n2-display\n3-find the second highest in the BST\n4-delte the node from BST\n5-total number of nodes having common parent");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("\ninput the data of bst");
      scanf("%d", &val);
      root = create(root, val);
      break;
    case 2:
      display(root);
      break;
    case 3:
      printf("\nSecond largest value is %d", secondhighest(root));
      break;
    case 4:
      printf("\ninput the data");
      scanf("%d", &num);
      delete (&root, num);
      break;
    case 5:
      common = countParent(root);
      printf("\ncommon parent are %d\n", common);
      break;
    case 6:
      heightNum = height(root);
      printf("\nheight of the BST is %d", heightNum);
      break;
    case 7:
      leftNum = leftNode(root);
      printf("\nleft node of BST is %d", leftNum);
      break;
    case 0:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice! Please try again.\n");
    }

  } while (ch != 0);
}
