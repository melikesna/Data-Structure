#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for student records
struct Student {
    int studentNumber;
    char name[50];
    int age;
    struct Student* next;
};

// Function to create a new student node
struct Student* createStudent(int number, const char* name, int age) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->studentNumber = number;
    strncpy(newStudent->name, name, sizeof(newStudent->name) - 1);  // Copy name to the struct (with boundary check)
    newStudent->age = age;
    newStudent->next = NULL;
    return newStudent;
}

// Function to traverse the list, print student information, and count nodes
int traverseAndPrint(struct Student* head) {
    int count = 0;
    struct Student* current = head;
    while (current != NULL) {
        printf("%d %s %d\n", ++count, current->name, current->age, current->studentNumber);
        current = current->next;
    }
    return count;
}

// Function to search for a student by name in the list
struct Student* searchByName(struct Student* head, const char* name) {
    struct Student* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;  // Return the node if name matches
        }
        current = current->next;
    }
    return NULL;  // Return NULL if name is not found
}

// Function to delete the next node from the node with the searched student name
void deleteNextNode(struct Student* head, const char* name) {
    struct Student* current = searchByName(head, name);
    if (current != NULL && current->next != NULL) {
        struct Student* temp = current->next;
        current->next = current->next->next;  // Skip the next node
        free(temp);  // Free the memory of the deleted node
    }
}

// Function to find and print the record with the longest name in the list
void printLongestNameRecord(struct Student* head) {
    int maxLength = 0;
    struct Student* current = head;
    struct Student* longestNameRecord = NULL;
    while (current != NULL) {
        int currentLength = strlen(current->name);
        if (currentLength > maxLength) {
            maxLength = currentLength;
            longestNameRecord = current;
        }
        current = current->next;
    }
    if (longestNameRecord != NULL) {
        printf("Record with the longest name: %d %s %d\n",
               longestNameRecord->studentNumber, longestNameRecord->name,
               longestNameRecord->age);
    } else {
        printf("No records found.\n");
    }
}

int main() {
    // Example usage of the functions
    struct Student* head = createStudent(1807, "Melike", 22);
    head->next = createStudent(1904, "Aras", 24);
    head->next->next = createStudent(2311, "Sena", 23);

    printf("Student information in the list:\n");
    int studentCount = traverseAndPrint(head);

    // Search for a student by name
    const char* searchName = "Aras";
    struct Student* foundStudent = searchByName(head, searchName);
    if (foundStudent != NULL) {
        printf("\nStudent found by name '%s': %d %s %d\n", searchName,
               foundStudent->studentNumber, foundStudent->name,
               foundStudent->age);
    } else {
        printf("\nStudent with name '%s' not found.\n", searchName);
    }

    // Delete the next node from the node with the searched student name
    deleteNextNode(head, searchName);
    printf("\nList after deleting the next node from '%s':\n", searchName);
    traverseAndPrint(head);

    // Print the record with the longest name in the list
    printf("\n");
    printLongestNameRecord(head);

    
    return 0;
}
