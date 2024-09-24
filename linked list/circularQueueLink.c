#include<stdio.h>
#include<stdlib.h>
typedef struct circular{
   int val;
   struct circular *next;
}circular;

circular * enqueue(circular *head)
{
  circular *temp,*newnode;
  temp=head;
  newnode=(circular *)malloc(sizeof(circular));
  newnode->next=head;
    printf("\n inout the value of the queue\n");
      scanf("%d",&newnode->val);
      if(head==NULL)
      {
        head = newnode;
        newnode->next = head; // Circular reference to itself
      }
      else{
        circular *temp = head;
        // Traverse to the last node
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;  // Link the last node to the new node
        newnode->next = head;  // Make the new node point to the head (circular)
      }
  return head;
}

void display(circular *head) {
    if (head == NULL) {
        printf("Queue is empty\n");
        return;
    }

    circular *temp = head;
    do {
        printf("The value is %d\n", temp->val);
        temp = temp->next;
    } while (temp != head);  // Stop when we come back to the head
}

circular *dequeue(circular *head)
{ circular *temp=head,*f=head;
    if(head==NULL)
    {
      printf("empty");
    }
    else{
      while(temp->next!=head)
      {
        temp=temp->next;
      }
      temp->next=head->next;
      head=head->next;
    }
    free(f);
    return head;
}

int main()
{
     circular *head=NULL;
     int ch;
     
     do{
    
      printf("\n1-enqueue\n2-display\n3-dequeue\n");
      scanf("%d",&ch);
      switch(ch){
        case 1:
        head=enqueue(head);
        break;
        case 2:
          display(head);
           break;
        case 3:
        head=dequeue(head);
        break;
      }
     }while(ch<=5);
}
