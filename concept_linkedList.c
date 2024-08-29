#include<stdio.h>
#include<stdlib.h>
typedef struct link{
    int val;
    struct link *next;
}link;
link makeLink(link *newnode,link *head,link *temp)
{  int ch;
    while(1){
    newnode=(link*)malloc(sizeof(link));
    printf("\nenter the data");
    scanf("%d",&newnode->val);
    if(head==NULL)
    {
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
    printf("\ndo you want to continue\nyes-0\nno-1");
    scanf("%d",&ch);
    if(ch==1)
    break;
    }
}
link display(link *head)
{
    while(head!=0)
   {printf("%d\t %d\n",head->next,head->val);          //first in first out
     head=head->next;                                 
     }
}

int main(){
    int choice;
    link *newnode=NULL,*head=NULL,*temp=NULL;
    printf("input the choice 1-make a linked list\n2-display\n3-insert node at the end\n3-insert node beggning\n4-exit");
    scanf("%d",&choice);
    do{
        switch(choice)
        {
            case 1:
              makeLink(newnode,head,temp);
              break;
              case 2:
              display(head);
               break;
            //   case 3:
            //   insertAtBegg(newnode,head);
            //   break;
             
        }
    }while(choice<=3);
}