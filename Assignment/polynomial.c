#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coeff;
    int pow;
    struct node *next;
} node;

node *createNode(int coeff, int pow)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

node *insertNode(node *head, int coeff, int pow)
{
    node *newNode = createNode(coeff, pow);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

void displayPoly(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->pow);
        if (temp->next != NULL)
        {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

node *addPoly(node *poly1, node *poly2)
{
    node *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->pow == poly2->pow)
        {
            result = insertNode(result, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->pow > poly2->pow)
        {
            result = insertNode(result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else
        {
            result = insertNode(result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        result = insertNode(result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        result = insertNode(result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }
    return result;
}

int main()
{
    node *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    int n, coeff, pow, i;

    printf("Enter the number of terms in polynomial 1: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        poly1 = insertNode(poly1, coeff, pow);
    }

    printf("Enter the number of terms in polynomial 2: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        poly2 = insertNode(poly2, coeff, pow);
    }

    printf("Polynomial 1: ");
    displayPoly(poly1);

    printf("Polynomial 2: ");
    displayPoly(poly2);

    sum = addPoly(poly1, poly2);

    printf("Sum of the two polynomials: ");
    displayPoly(sum);

    return 0;
}




