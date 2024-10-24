//using double pointer

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int data;
struct node*left,*right;
}node;

node *create(int data)
{ node *newnode=(node*)malloc(sizeof(node));
newnode->data=data;
newnode->left=NULL;
newnode->right=NULL;
return newnode;
}

void insert (node** root,int data)
{  if(*root==NULL)
 { *root=create(data);
 return;
 }
 if(data<(*root)->data)
 { 
    insert (&((*root)->left),data);
 }
 else if(data>(*root)->data)
   {  insert(&((*root)->right),data);
   }
   }
   
   void inorder(node *root)
     { 
     if(root!=NULL){
        inorder(root->left);
        printf("%d  ",root->data);
        inorder(root->right);
        }
}
        
        
  int main()
  {  struct node *root=NULL;
      insert(&root,50);
      insert(&root,40);
      insert(&root,20);
      insert(&root,70);
      insert(&root,80);

 printf("\n\n------IN order-------\n");
 inorder(root);
 
 return 0;
 }
