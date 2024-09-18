//REVERSE THE LINKED LIST

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node *creation(node *head, node *newnode, node *temp)
{
    head = NULL, newnode = NULL, temp = NULL;
    int ch = 1;
    while (ch == 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter data :");
        scanf("%d", &newnode->data);
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
        printf("Do you want to continue (0,1)?\n");
        scanf("%d", &ch);
        if (ch == 0)
            break;
    }
    return head;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
node *reverse(node *head)
{
    struct node *prevnode, *currentnode, *nextnode;
    prevnode = 0;
    currentnode = nextnode = head;
    while (nextnode != NULL)
    {
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }

    return prevnode;
}
int main()
{
    int choice;

    node *newnode = NULL, *head = NULL, *temp = NULL;

    do
    {
        printf("\nenter choice :\n1 to create node \n2 to reverse :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = creation(head, newnode, temp);
            printf("elements in the linked list are : ");
            display(head);
            break;
        case 2:
            head = reverse(head);
            printf("elements in the linked list after reversing are : ");
            display(head);
            break;
        }
    } while (choice <= 2);
}
