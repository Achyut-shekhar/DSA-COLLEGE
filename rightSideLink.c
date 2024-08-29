#include<stdio.h>
#include<stdlib.h>
typedef struct link{
 int val;
 struct link *next;
 }link;
int main()
{  link *head=NULL,*newnode=NULL,*temp=NULL;
int choice;
while(1)
{
   newnode=(link *)malloc(sizeof(link));
   printf("enter the data\n");
   scanf("%d",&newnode->val);
   if(head==NULL)
   { head=temp=newnode;   //at first node head is NULL and therefore we are saving the first node address
                          //in head
   }
   else
   { temp->next=newnode;  //after saving the first address in the head we need to save the next node address in the first node and we have the address of first node from temp 
                          //from this we will not loose first address from head and we can save the next node address with temp
   temp=newnode;         //at last we will save the address of the newnode in temp
   }
   printf("\ndo you want to continue yes-1 no-0");
   scanf("%d",&choice);
   if(choice==0)
   break;
   }
   while(head!=0)
   {printf("%d\t %d\n",head->next,head->val);          //first in first out
     head=head->next;                                 
     }
   }
   
   
