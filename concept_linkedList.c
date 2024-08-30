#include<stdio.h>
#include<stdlib.h>
typedef struct link{
    int val;
    struct link *next;
}link;
link *makeLink(link *newnode, link *head, link *temp) {
    int ch;
    while (1) {
        newnode = (link *)malloc(sizeof(link));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            break;
        }
        printf("Enter the data: ");
        scanf("%d", &newnode->val);
        newnode->next = NULL;  // Ensure the new node terminates the list

        if (head == NULL) {
            head = temp = newnode;  // Initialize the head for the first node
        } else {
            temp->next = newnode;  // Link the new node
            temp = newnode;  // Move the temp pointer to the new node
        }

        printf("\nDo you want to continue? Yes-1 No-0: ");
        scanf("%d", &ch);
        if (ch == 0) {
            break;  // Break from the loop if the user inputs 0
        }
    }
    return head;  // Return the head of the list
}


void display(link *head)
{   printf("\nthe display of the linked list is:-\n");
    while(head!=NULL)
   {
    printf("\n%p is the address of %d value\n",head->next,head->val);          //first in first out
     head=head->next;                                 
     }
}
link * insertNextBegg(link *newnode,link *head)
{
    
        newnode = (link *)malloc(sizeof(link));
        printf("Enter the data: ");
        scanf("%d", &newnode->val);
        newnode->next=head->next;
        head->next=newnode;
        return head;
    
}
link *insertbeforeBegg(link *newnode,link *head)
{
        newnode = (link *)malloc(sizeof(link));
        printf("Enter the data: ");
        scanf("%d", &newnode->val);
        newnode->next=head;  //head address is stored in newnode
        head=newnode;        //the head value is updated with newnode as it is now first node
        return head;
}
int main(){
    int choice;
    link *newnode=NULL,*head=NULL,*temp=NULL;
    
    do{
        printf("\n\ninput the choice\n 1-make a linked list\n2-display\n3-insert node next the beggining \n4-insert node before the beggning\n5-exit");
    scanf("%d",&choice);
        switch(choice)
        {
            case 1:
             head= makeLink(newnode,head,temp);
              break;
              case 2:
              display(head);
               break;
              case 3:
              insertNextBegg(newnode,head);
              break;
              case 4:
              head=insertbeforeBegg(newnode,head); //head will be updated
              break;
             
        }
    }while(choice<=5);
}