#include <stdio.h>
#include <stdlib.h>

// Define a struct for a Node in the linked list
struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node in the list
};

// Function to add a new node with given value to the front of the list
void addToFront(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // Allocate memory for the new node
    newNode->data = value;  // Set the data of the new node
    newNode->next = *head;  // Point the new node to the current head of the list
    *head = newNode;        // Update the head to point to the new node
}

// Function to separate odd and even numbers in the list and print them
void separateOddEven() {
    struct Node* oddNumbers = NULL;   // Initialize an empty list for odd numbers
    struct Node* evenNumbers = NULL;  // Initialize an empty list for even numbers
    int number;

    printf("Enter a number (-1 to stop): ");
    scanf("%d", &number);

    // Read numbers from the user until -1 is entered
    while (number != -1) {
        if (number % 2 == 0) {
            addToFront(&evenNumbers, number);  // Add even number to the front of evenNumbers list
        } else {
            addToFront(&oddNumbers, number);   // Add odd number to the front of oddNumbers list
        }

        printf("Enter a number (-1 to stop): ");
        scanf("%d", &number);
    }

    // Print odd numbers
    printf("Odd numbers: ");
    struct Node* oddPtr = oddNumbers;
    while (oddPtr != NULL) {
        printf("%d ", oddPtr->data);
        oddPtr = oddPtr->next;
    }

    // Print even numbers
    printf("\nEven numbers: ");
    struct Node* evenPtr = evenNumbers;
    while (evenPtr != NULL) {
        printf("%d ", evenPtr->data);
        evenPtr = evenPtr->next;
    }
}

int main() {
    separateOddEven();  // Call the function to separate and print odd and even numbers
    return 0;
}
