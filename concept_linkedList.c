#include <stdio.h>
#include <stdlib.h>
typedef struct link
{
    int val;
    struct link *next;
} link;
link *makeLink(link *newnode, link *head, link *temp)
{
    int ch;
    while (1)
    {
        newnode = (link *)malloc(sizeof(link));
        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            break;
        }
        printf("Enter the data: ");
        scanf("%d", &newnode->val);
        newnode->next = NULL; // Ensure the new node terminates the list

        if (head == NULL)
        {
            head = temp = newnode; // Initialize the head for the first node
        }
        else
        {
            temp->next = newnode; // Link the new node
            temp = newnode;       // Move the temp pointer to the new node
        }

        printf("\nDo you want to continue? Yes-1 No-0: ");
        scanf("%d", &ch);
        if (ch == 0)
        {
            break; // Break from the loop if the user inputs 0
        }
    }
    return head; // Return the head of the list
}

void display(link *head)
{
    printf("\nthe display of the linked list is:-\n");
    while (head != NULL)
    {
        printf("\n%p is the address of %d value\n", head->next, head->val); // first in first out
        head = head->next;
    }
}
link *insertNextBegg(link *newnode, link *head)
{

    newnode = (link *)malloc(sizeof(link));
    printf("Enter the data: ");
    scanf("%d", &newnode->val);
    newnode->next = head->next;
    head->next = newnode;
    return head;
}
link *insertbeforeBegg(link *newnode, link *head)
{
    newnode = (link *)malloc(sizeof(link));
    printf("Enter the data: ");
    scanf("%d", &newnode->val);
    newnode->next = head; // head address is stored in newnode
    head = newnode;       // the head value is updated with newnode as it is now first node
    return head;
}
void insertAfterEnd(link *newnode, link *head)
{
    newnode = (link *)malloc(sizeof(link));
    printf("Enter the data: ");
    scanf("%d", &newnode->val);
    link *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;

    return head;
}
void insertBeforeEnd(link *newnode, link *head)
{
    newnode = (link *)malloc(sizeof(link));
    printf("Enter the data: ");
    scanf("%d", &newnode->val);
    link *temp = head;
    link *temp1;
    while (temp->next != NULL)
    {
        // it will be before assigning the next because if we not then at last when it will find null temp1 and temp will have same address in them
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = newnode;
    newnode->next = temp;
}
link *deletenode(link *newnode, link *head)
{
    int deleteVal;
    printf("\nenter the value of the node you want to delete:-\n");
    scanf("%d", &deleteVal);
    link *before, *nodeDel, *after;
    nodeDel = head;
    if (head->val != deleteVal)
    {
        while (nodeDel->val != deleteVal)
        {
            before = nodeDel;
            after = nodeDel->next;
            nodeDel = nodeDel->next;
        }
        before->next = after->next;
    }
    else
    {
        head = head->next;  
    }
    return head;
}

void insertBetweenNode(link *newnode,link *head)
{    int nodelocation;
     int pos;
    newnode = (link *)malloc(sizeof(link));
    printf("Enter the data: ");
    scanf("%d", &newnode->val);
    link *temp = head;
    printf("before node-1\nafter node-0");
    scanf("%d",&pos);
    if(pos){
    printf("input the value of node before you want to add node");
    scanf("%d",&nodelocation);
    while (temp->next->val != nodelocation)
    {
        temp=temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    }
    else
    { printf("input the value of node after you want to add node");
    scanf("%d",&nodelocation);
    while (temp->val != nodelocation)
    {
        temp=temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    }
}
link *reverselink(link *newnode,link *head)
{  link *curr=head,*prev=NULL,*after;
while (curr != NULL) {

        // Store next
        after = curr->next;

        // Reverse current node's next pointer
        curr->next = prev;

        // Move pointers one position ahead
        prev = curr;
        curr = after;
    }
   return prev;
    
   }
int main()
{
    int choice;
    link *newnode = NULL, *head = NULL, *temp = NULL;

    do
    {
        printf("\n\ninput the choice\n1-make a linked list\n2-display\n3-insert node next the beggining \n4-insert node before the beggning\n5-insert after thee end node\n6-insert before the end node\n7-delete the node\n8-insert node in between linked list\n9-reverse the linked list");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = makeLink(newnode, head, temp);
            break;
        case 2:
            display(head);
            break;
        case 3:
            insertNextBegg(newnode, head);
            break;
        case 4:
            head = insertbeforeBegg(newnode, head); // head will be updated
            break;
        case 5:
            insertAfterEnd(newnode, head);
            break;
        case 6:
            insertBeforeEnd(newnode, head);
            break;
        case 7:
            head=deletenode(newnode, head);
            break;
        case 8:
            insertBetweenNode(newnode,head);
            break;
         case 9:
            head=reverselink(newnode,head);
            break;
        }
    } while (choice <= 10);
}
