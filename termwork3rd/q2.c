#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
char name[100];
int roll;
struct node* next;
}node;
node *createlink(node *head)
{
  node *temp = NULL, *newnode = NULL;
  int ch = 0;
  while (1)
  {
    newnode = (node *)malloc(sizeof(node));
    printf("\ninput the roll number");
    scanf("%d", &newnode->roll);
    printf("\ninput the name");
    scanf("%s", &newnode->name);
    newnode->next = NULL;
    if (head == NULL)
    {
      head = temp = newnode;
    }
    else
    {
      temp->next = newnode;
      temp = newnode;
    }
    printf("\nif dont want to continue press 0");
    scanf("%d", &ch);
    if (ch == 0)
      break;
  }
  return head;
}
void display(node *head)
{
  
  while (head != NULL)
  {
    printf("\n%d->%s", head->roll,head->name);
    head = head->next;
  }
}
void compare(node *head)
{
   node *temp=head,*root=NULL,*prev=head;
   while(head!=NULL)
   {   temp=head->next;
       while(temp!=NULL)
       {  
          if (strcmp(head->name, temp->name) == 0) {  
                prev->next = temp->next;  
                free(temp);  
                temp = prev->next;  
            } else {
                prev = temp;   
                temp = temp->next;  
            }
      
       }
       head=head->next;
       
   }
}
int main()
{  
    node *head=NULL;
    int ch;
    do{
    printf("\ninput the choices:\n1-create a link\n2-display a link\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
       head=createlink(head);
       break;
      case 2:
        display(head);
       break;
      case 3:
       compare(head);
       break;
    }
    }while(ch!=0);
}
