#include <stdio.h>
#include <stdlib.h>
typedef struct binary
{
  int data;
  struct binary *left;
  struct binary *right;
} binary;

//creating a binary tree
binary *createbinary()
{
  binary *newnode;
  newnode = (binary *)malloc(sizeof(binary));
  printf("enetr the data:");
  scanf("%d", &newnode->data);
  if (newnode->data == -1)
    return 0;
  printf("\nenter the left child of %d:", newnode->data);
  newnode->left = createbinary(); //when there will be -1 when this function is calling then it will terminate till this line and next line will be executed;
  printf("\nenter the data of right child of %d:", newnode->data);
  newnode->right = createbinary();
  return newnode;
}
void levelOrderTraversal(){

}
int main()
{
  binary *root;
  root = createbinary();

  
}
