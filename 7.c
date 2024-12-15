#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    char usn[20], name[20], branch[10], phno[15];
    int sem;
    struct Node *next;
};
struct Node *head = NULL;
int count = 0;
void insertFront() {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter USN, Name, Branch, Semester, and Phone Number: ");
    scanf("%s %s %s %d %s", newNode->usn, newNode->name, newNode->branch, &newNode->sem, newNode->phno);
    newNode->next = head;
    head = newNode;
    count++;
}
void insertEnd() {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)), *temp = head;
    printf("\nEnter USN, Name, Branch, Semester, and Phone Number: ");
    scanf("%s %s %s %d %s", newNode->usn, newNode->name, newNode->branch, &newNode->sem, newNode->phno);
    newNode->next = NULL;
    if (!head) {
        head = newNode;
    } else {
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    count++;
}

void deleteFront() {
    if (!head) {
        printf("\nList is empty.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    printf("\nDeleted: %s %s %s %d %s\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
    free(temp);
    count--;
}
void deleteEnd() {
    if (!head) {
        printf("\nList is empty.\n");
        return;
    }
    struct Node *temp = head, *prev = NULL;
    if (!temp->next) {
        head = NULL;
    } else {
        while (temp->next) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
    }
    printf("\nDeleted: %s %s %s %d %s\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
    free(temp);
    count--;
}
void display() {
    if (!head) {
        printf("\nList is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("\nStudent List:\n");
    while (temp) {
        printf("%s %s %s %d %s\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
        temp = temp->next;
    }
    printf("Total Students: %d\n", count);
}
int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n1. Insert at Front\n2. Insert at End\n3. Delete from Front\n4. Delete from End\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertFront(); break;
            case 2: insertEnd(); break;
            case 3: deleteFront(); break;
            case 4: deleteEnd(); break;
            case 5: display(); break;
            case 6: printf("\nExiting.\n"); return 0;
            default: printf("\nInvalid choice.\n");
        }
    }
}
