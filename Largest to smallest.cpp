#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct for a Node in the linked list
struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node in the list
};

// Function to create a new node with given value
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // Allocate memory for the new node
    newNode->data = value;  // Set the data of the new node
    newNode->next = NULL;   // The new node initially points to NULL
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);  // Create a new node with the given value
    newNode->next = *head;  // Point the new node to the current head of the list
    *head = newNode;        // Update the head to point to the new node
}

// Function to perform bubble sort on the linked list (sorting in descending order)
void bubbleSort(struct Node* head) {
    int swapped, temp;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    // Checking for empty list
    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data < ptr1->next->data) {
                // Swap data of adjacent nodes if they are in the wrong order
                temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to print the elements of the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* numbersList = NULL;  // Initialize an empty list for numbers
    int i, randomNumber;

    // Seed for the random number generator
    srand(time(NULL));

    // Add 100 randomly generated numbers to the list
    for (i = 0; i < 100; ++i) {
        randomNumber = rand() % 1000;  // Generate a random number between 0 and 999
        insertNode(&numbersList, randomNumber);  // Insert the random number into the list
    }

    printf("Original list of numbers:\n");
    printList(numbersList);  // Print the original list

    // Sort the list from largest to smallest using bubble sort
    bubbleSort(numbersList);

    printf("Sorted list of numbers (largest to smallest):\n");
    printList(numbersList);  // Print the sorted list

    return 0;
}
