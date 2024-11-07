#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element to the linked list
void push(Node** head_ref, int new_data) {
    Node* newNode = createNode(new_data);
    newNode->next = *head_ref;
    *head_ref = newNode;
}

// Function to reverse a linked list
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to check if the linked list is a palindrome
int isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) return 1;

    // Step 1: Find the middle (slow will point to the middle node)
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the list
    Node* secondHalf = reverse(slow);
    Node* firstHalf = head;

    // Step 3: Compare both halves
    Node* tempSecond = secondHalf;
    while (tempSecond != NULL) {
        if (firstHalf->data != tempSecond->data) {
            return 0;  // Not a palindrome
        }
        firstHalf = firstHalf->next;
        tempSecond = tempSecond->next;
    }

    // Optional Step 4: Restore the list (re-reverse the second half)
    reverse(secondHalf);

    return 1;  // Palindrome
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // Creating a linked list
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Original list:\n");
    printList(head);

    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    return 0;
}
